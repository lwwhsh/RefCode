#! /bin/bash

export EPICS_CA_ADDR_LIST="172.17.101.200 172.17.101.201 172.17.101.90 172.17.101.180 172.17.101.101 172.17.101.104 172.17.101.142 172.17.102.22"
export EPICS_CA_AUTO_ADDR_LIST=YES

../../bin/linux-x86/sncMdsPutTSS "FNAME=mdsPutTssList.tss"
