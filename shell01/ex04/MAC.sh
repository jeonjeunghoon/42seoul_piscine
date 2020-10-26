#!/bin/bash

ifconfig -a | grep -w ether | sed 's/ether//g' | awk '{$1=$1}1'
