
trace signals will dump out lots of info, and show you what each signal value is. Good for finding X/U etc:
./top --trace-signals
./top --vcd=file_name.vcd --assert-level=none --ieee-asserts=disable
