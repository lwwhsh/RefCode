TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
#  Optimization of db files using dbst (DEFAULT: NO)
#DB_OPT = YES

#----------------------------------------------------
# Create and install (or just install)
# databases, templates, substitutions like this
DB += dbExample1.db
DB += dbExample2.db
DB += dbSubExample.db

#DB += dbSysMon.db

DB += GCDS_timeStamp.db
DB += NIDAQ.db
DB += NIDAQ_READ_CH_DAQ.db 
DB += NIDAQ_READ_CH_DAQ.template
DB += $(EPICS_SITE)/db/dbSFW.db 
DB += $(EPICS_SITE)/db/dbSysMon.db 
 
#----------------------------------------------------
# If <anyname>.db template is not named <anyname>*.template add
# <anyname>_TEMPLATE = <templatename>

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

