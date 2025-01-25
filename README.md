# eater-emulator

![example](https://cloud-q1rp8sz0d-hack-club-bot.vercel.app/0screenshot_20250125_172034.png)

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
Press enter to step through the program, or `m` to dump the memory.

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

For more examples, see the `examples` directory
