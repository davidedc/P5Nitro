#!/bin/sh

for X in `ps acx | grep -i $1 | awk {'print $1'}`; do
  kill $X;
done
