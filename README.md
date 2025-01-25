# eater-emulator

## Usage

### Compiling
```
git clone https://github.com/kijenasa/eater-emulator.git
cd eater-emulator
gcc src/* -o emulator
```

### Running
```
./emulator path/to/program.asm
```

### Assembly

The emulator assembles the inputted file and dumps it into the memory.
The syntax is 
```
opcode argument
```
You can immediate values into memory with a `$`. For example:
```
$7
```
will put 7 into memory.
