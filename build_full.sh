#!/bin/bash

tower DSA.Vent.Tower.dbnf DSA::Vent::Tower::CPPGenerator

$(dirname $0)/build_source.sh
