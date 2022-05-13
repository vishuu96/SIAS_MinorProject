#!/bin/bash

for ((i = 1; i < 10; i = i + 1)); do

echo "===================="
echo "PIR - 0.00$i"
echo "===================="

time ./noxim -config ./sias_config.yaml -pir "0.00"$i poisson

echo ""
echo ""

done

for ((i = 10; i < 56; i = i + 1)); do

echo "===================="
echo "PIR - 0.0$i"
echo "===================="

time ./noxim -config ./sias_config.yaml -pir "0.0"$i poisson

echo ""
echo ""

done
