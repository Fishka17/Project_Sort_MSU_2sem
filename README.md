# Project_Sort_MSU_2sem
compare 2 sorted methods

Command for build Project:

gcc-15 -O2 -Wall -Werror -Wformat-security -Wignored-qualifiers \
-Winit-self -Wswitch-default -Wfloat-equal -Wpointer-arith \
-Wtype-limits -Wempty-body -Wno-logical-op -Wstrict-prototypes \
-Wold-style-declaration -Wold-style-definition -Wmissing-parameter-type \
-Wmissing-field-initializers -Wnested-externs -Wno-pointer-sign \
-Wno-unused-result -std=gnu99 -lm main.c Functions/MassiveGenerator.c Functions/Sorts/BubbleSort.c -o main