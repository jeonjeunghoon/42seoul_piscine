#!/bin/bash

find . -name '*.sh' -exec basename {} \; | sed 's/\.sh$//';
