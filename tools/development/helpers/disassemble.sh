#!/usr/bin/env bash

################################################################################################################################################################

# @project        ESP 8266
# @file           tools/development/helpers/disassemble.sh
# @author         Lucas Brémond <lucas.bremond@gmail.com>
# @license        MIT License

################################################################################################################################################################

/opt/esp-open-sdk/xtensa-lx106-elf/xtensa-lx106-elf/bin/objdump -d /app/out/build/app.out > /app/out/disassemble.txt

################################################################################################################################################################
