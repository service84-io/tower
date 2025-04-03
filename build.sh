#!/bin/bash

if [ -f ./tower ]; then
  ./tower DSA.Vent.Tower.dbnf DSA::Vent::Tower::CPPGenerator
fi

gcc *.cpp -lstdc++ -o tower
