#define PAD_NUMBER(num) ((num) < 10 ? "00" : (num) < 100 ? "0" : ""), (num)

#define DIAGRAM(pc, mar, mem, ir, ra, rb, out, bus) \
    printf( \
        "                           ┌─────┐┌─────────────────┐\n" \
        "                           │ Bus ││ Program Counter │\n" \
        "                           │     ││  %s%d            │\n" \
        "                           │     │└─────────────────┘\n" \
        "┌─────────────────────────┐│     │┌─────────────────┐\n" \
        "│ Memory Address Register ││     ││ Register A      │\n" \
        "│                    %s%d  ││     ││  %s%d            │\n" \
        "└─────────────────────────┘│     │└─────────────────┘\n" \
        "┌─────────────────────────┐│     │                   \n" \
        "│                  Memory ││     │                   \n" \
        "│                    %s%d  ││     │                   \n" \
        "└─────────────────────────┘│     │                   \n" \
        "┌─────────────────────────┐│     │┌─────────────────┐\n" \
        "│    Instruction Register ││     ││ Register B      │\n" \
        "│                    %s%d  ││     ││  %s%d            │\n" \
        "└─────────────────────────┘│     │└─────────────────┘\n" \
        "                           │     │┌─────────────────┐\n" \
        "                           │     ││ Output          │\n" \
        "                           │     ││  %s%d            │\n" \
        "                           │ %s%d │└─────────────────┘\n" \
        "                           └─────┘ github.com/kijenasa\n", \
        PAD_NUMBER(pc), PAD_NUMBER(mar), PAD_NUMBER(mem), PAD_NUMBER(ir), PAD_NUMBER(ra), PAD_NUMBER(rb), PAD_NUMBER(out), PAD_NUMBER(bus) \
    );
