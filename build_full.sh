#!/bin/bash

tower DSA.Vent.Tower.dbnf DSA::Vent::Tower::CPPGenerator
tower DSA.Vent.Tower.dbnf DSA::Vent::Tower::CTCodeGeneratorBoot

ctcode DSA.Vent.Tower.dbnf.ctcode s84::ctcode::CPPTranspiler

$(dirname $0)/build_source.sh
