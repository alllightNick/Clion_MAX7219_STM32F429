#!/bin/bash
CFGNAME=`basename $1`
RUNCMD="/home/nick/openocd/bin/openocd -f $CFGNAME"
cd `dirname $1`
xterm -fg green -bg black -geometry 100x24-0-0 -e $RUNCMD &
