#!/usr/bin/env bash

iptables -L -n | awk '$1=="REJECT" && $4!="0.0.0.0/0"'
