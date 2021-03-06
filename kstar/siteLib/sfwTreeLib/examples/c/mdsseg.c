#include <mdslib.h>

/* Define a macro to check status of MDSplus functions */
#define status_ok(status) (((status) & 1) == 1)

#define	SERVER_ADDR	"127.0.0.1:8000"
#define	TREE_NAME	"r_spectro"
#define	SHOT_NUM	1
#define TAG_NAME	"\\TOR_VB01:FOO"
#define	EVENT_NAME	"VBS"

#define	USE_CONNECT	0

int open_tree (char *host, char *tree, int shot)
{
	int status;
	int socket;

#if USE_CONNECT
	/* Connect to MDSplus */
	socket = MdsConnect (host);
	if ( socket == -1 ) {
		fprintf(stderr,"Error connecting to %s.\n", host);
		return EXIT_FAILURE;
	}
#endif

	/* Open tree */
	status = MdsOpen (tree, &shot);
	if ( !status_ok(status) ) {
		fprintf(stderr,"Error opening %s tree for shot %d.\n", tree, shot);
		return EXIT_FAILURE;
	}

	return 0;
}

int close_tree (char *host, char *tree, int shot)
{
	MdsClose (tree, &shot);

#if USE_CONNECT
	MdsDisconnect();
#endif

	return 0;
}

int create_tree (char *host, char *tree, int shot)
{
	int     null = 0; /* Used to mark the end of the argument list */
	int     tstat, len;
	char    buf[128];
	int     dtype_Long = DTYPE_LONG; /* The returned value of SIZE() is an  integer */
	int     idesc = descr(&dtype_Long, &tstat, &null);
	int		status;

	sprintf(buf, "TCL(\"set tree %s/shot=-1\")", tree);

	status = MdsValue(buf, &idesc, &null, &len);
	if ( !status_ok(status) ) {
		fprintf (stderr, "Error TCL command: %s.\n", buf);
		return EXIT_FAILURE;
	}

	sprintf(buf, "TCL(\"create pulse %d\")", shot);

	status = MdsValue(buf, &idesc, &null, &len);
	if ( !status_ok(status) ) {
		fprintf (stderr, "Error TCL command: %s.\n", buf);
		return EXIT_FAILURE;
	}

	sprintf(buf, "TCL(\"close\")");
	MdsValue(buf, &idesc, &null, &len);

	fprintf (stderr, "Create new tree(%d)... OK\n", shot);

	return (0);
}

int set_event (char *host, char *eventName)
{
	int size;
	int null = 0;
	int status;
	int len;
	char buf[1024];
	int dtype_Long = DTYPE_LONG;
	int idesc = descr(&dtype_Long, &size, &null);

	sprintf(buf, "TCL(\"setevent %s\")", eventName);
	status = MdsValue (buf, &idesc, &null, &len);

	if ( !status_ok(status) ) {
		fprintf(stderr,"Error TCP(setevent %s): %s.\n", eventName, MdsGetMsg(status));
		return EXIT_FAILURE;
	}

	printf ("setevent %s\n", eventName);

	return 0;
}

int get_signal_length(const char *signal)
{
	/* local vars */
	int dtype_long = DTYPE_LONG;
	char buf[1024];
	int size;
	int null = 0;
	int idesc = descr(&dtype_long, &size, &null);
	int status;

	/* init buffer */
	memset(buf,0,sizeof(buf));

	/* put SIZE() TDI function around signal name */
	snprintf(buf,sizeof(buf)-1,"SIZE(%s)",signal);

	/* use MdsValue to get the signal length */
	status = MdsValue(buf, &idesc, &null, 0);
	if ( !status_ok(status) ) {
		fprintf(stderr,"Unable to get length of %s.\n",signal);
		return EXIT_FAILURE;
	}

	printf ("SIZE(%s) : %d\n", signal, size);

	return size;
}

int get_signal (char *signal)
{
	/* local vars */
	int dtype_float = DTYPE_FLOAT;
	int null = 0;
	int status;
	float *data;     /* array of floats used for signal */
	float *timebase; /* array of floats used for timebase */
	int sigdesc;     /* signal descriptor */
	int timedesc;    /* descriptor for timebase */
	int size;        /* length of signal */
	int i, len;
	char buf[1024];

	/* use get_signal_length to get size of signal */
	size = get_signal_length (signal);
	if ( size < 1 ) {
		/* error */
		fprintf(stderr,"Error retrieving length of signal\n");
		return EXIT_FAILURE;
	}

	/* use malloc() to allocate memory for the signal */
	data = (float *)malloc(size * sizeof(float));
	if ( !data ) {
		fprintf(stderr,"Error allocating memory for data\n");
		return EXIT_FAILURE;
	}

	/* create a descriptor for this signal */
	sigdesc = descr(&dtype_float, data, &size, &null);

	/* retrieve signal */
	status = MdsValue (signal, &sigdesc, &null, &len );
	if ( !status_ok(status) ) {
		/* error */
		fprintf(stderr,"Error retrieving signal\n");
		free( (void *)data );
		return EXIT_FAILURE;
	}

	/* use malloc() to allocate memory for the timebase */
	timebase = (float *)malloc(size * sizeof(float));
	if ( !timebase ) {
		fprintf(stderr,"Error allocating memory for timebase");
		free( (void *)data );
		return EXIT_FAILURE;
	}

	/* create a descriptor for the timebase */
	timedesc = descr(&dtype_float, timebase, &size, &null);

	/* retrieve timebase of signal */
	snprintf(buf,sizeof(buf)-1,"DIM_OF(%s)", signal);

	status = MdsValue(buf, &timedesc, &null, 0);
	if ( !status_ok(status) ) {
		/* error */
		fprintf(stderr,"Error retrieving timebase\n");
		free( (void *)data );
		free( (void *)timebase );
		return EXIT_FAILURE;
	}

	/* example: print first 10 data points */
	for ( i = 0 ; i < size && i < 100 ; i++ ) {
		printf("%i  X:%f  Y:%f\n", i, timebase[i], data[i]);
	}

	/* free the dynamically allocated memory when done */
	free( (void *)data );
	free( (void *)timebase );

	/* done */
	return 0;
}

int put_signal_segment (char *signal, int idx, float start, float end, float rate, int cnt, void *data)
{
	printf ("put : idx(%d) start(%f) end(%f) rate(%f) cnt(%d)\n", idx, start, end, rate, cnt);

	int null = 0;
	int status;
	int len;
	int tstat;

	int dtype_Float = DTYPE_FLOAT;
	int dtype_Long = DTYPE_LONG;
	int dtype_cstring = DTYPE_CSTRING;

	start = start * rate;
	end = end * rate;
	int startDesc	= descr(&dtype_Float, &start, &null); // T0 - Blip
	int endDesc		= descr(&dtype_Float, &end, &null);
	int dimDesc		= descr(&dtype_Float, &rate, &null);
	int valueDesc	= descr(&dtype_Float, (void *)data, &cnt, &null);
	float range		= 1;
	int rangeDesc   = descr(&dtype_Float, &range, &null);
	int idesc		= descr(&dtype_Long, &tstat, &null);

	int bufsize = 1024;
	char buf[1024];

#if 1

#if 0
	// Negative time is NOK
	sprintf (buf, "BeginSegment(%s,$,$,MAKE_DIM(MAKE_WINDOW(0,$,$),MAKE_SLOPE(MAKE_WITH_UNITS($,\"s\"))),$,%d)", signal, idx);
	status = MdsValue (buf, &startDesc, &endDesc, &endDesc, &startDesc, &dimDesc, &valueDesc, &idesc, &null, &len);
#elif 1
	// Negative time is OK
	sprintf (buf, "BeginSegment(%s,$,$,MAKE_DIM(MAKE_WINDOW($,$,0),MAKE_SLOPE(MAKE_WITH_UNITS($,\"s\"))),$,%d)", signal, idx);
	status = MdsValue (buf, &startDesc, &endDesc, &startDesc, &endDesc, &dimDesc, &valueDesc, &idesc, &null, &len);
#else
	// Negative time is OK
	sprintf (buf, "BeginSegment(%s,$,$,MAKE_DIM(MAKE_WINDOW($,$,0),MAKE_SLOPE(MAKE_WITH_UNITS($,\"s\"))),BUILD_WITH_UNITS($,\"V\"),%d)", signal, idx);
	status = MdsValue (buf, &startDesc, &endDesc, &startDesc, &endDesc, &dimDesc, &valueDesc, &idesc, &null, &len);
#endif

#else

	// Negative time : v4.0.0 (OK), v2.3.0 & v3.0.1 (NOK)
	sprintf (buf, "BeginSegment(%s,-3,9,MAKE_DIM(MAKE_WINDOW(-1,3,0),MAKE_SLOPE(3)),$,%d)", signal, idx);
	status = MdsValue (buf, &valueDesc, &idesc, &null, &len);
#endif

	if ( !status_ok(status) ) {
		fprintf (stderr, "Error BeginSegment : %s\n", MdsGetMsg(status));
		return EXIT_FAILURE;
	}

	printf ("%s\n", buf);

#if 0
	sprintf (buf, "PutSegment(%s,%d,BUILD_SIGNAL(BUILD_WITH_UNITS($*$,\"V\"),,MAKE_DIM(MAKE_WINDOW(0,$,$),MAKE_SLOPE(MAKE_WITH_UNITS($,\"s\")))))",
		signal, idx);
	status = MdsValue (buf, &valueDesc, &rangeDesc, &endDesc, &startDesc, &dimDesc, &idesc, &null, &len);

	if ( !status_ok(status) ) {
		fprintf (stderr, "Error PutSegment : %s\n", MdsGetMsg(status));
		return EXIT_FAILURE;
	}

	printf ("%s\n", buf);
#endif

	set_event (SERVER_ADDR, EVENT_NAME);

	return 0;
}

int put_signal_long_pulse (char *signal)
{
	int	i, j;
	float offset = -10.0;
	float start;
	float end;
	float rate	= 1.0;
	int	 cnt	= 10;
	float data[10] = {0};

	for (i = 0; i < 3; i++) {
		start	= i * cnt + offset;
		end		= start + cnt - 1;

		for (j = 0; j < 10; j++) {
			data[j]	= start + j;
		}

		put_signal_segment (signal, -1, start, end, rate, cnt, data);
		//put_signal_segment (signal, i, start, end, rate, cnt, data);

		get_signal (signal);
		sleep (2);
	}

	return 0;
}

int main (int argc, char *argv[])
{
	//create_tree (SERVER_ADDR, TREE_NAME, SHOT_NUM);

	open_tree (SERVER_ADDR, TREE_NAME, SHOT_NUM);

	put_signal_long_pulse (TAG_NAME);

	close_tree (SERVER_ADDR, TREE_NAME, SHOT_NUM);

	return (0);
}
