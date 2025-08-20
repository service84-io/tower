#!/bin/bash

tower S84.Tower.dbnf DSA::Vent::Tower::CTCodeGenerator
echo

echo Processing CTCode files...
echo

for CTCodeFile in *.ctcode; do
  echo Processing ${CTCodeFile}...
  ctcode ${CTCodeFile} s84::ctcode::CPPTranspiler
  echo Done processing ${CTCodeFile}!
  echo
done

echo Done processing CTCode files!
echo

$(dirname $0)/build_source.sh
