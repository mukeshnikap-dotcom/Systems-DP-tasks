#!/bin/bash

LOG="${1:-demo_log.log}" #protection one can either pass his own log file or use the demo
if [ ! -f "$LOG" ]; then
    echo "log file $LOG not found"
    exit 1
fi

grep '\[WARN\] DROPPED_FRAME' "$LOG" \
    | sed 's/.*sensor_id=\([A-Za-z0-9_]*\)*.*/\1/' \
    | sort \
    | uniq -c \
    | sort -rn