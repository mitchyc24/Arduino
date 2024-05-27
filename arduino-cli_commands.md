
## A list of useful cli commands

### compile
arduino-cli compile --fqbn arduino:avr:nano FirstTestSketch


### upload
arduino-cli upload -p COM3 --fqbn arduino:avr:nano:cpu=atmega328old FirstTestSketch -v