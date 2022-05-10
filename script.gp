set term pdf
set out "Graficas.pdf"
set xlabel "Probabilidad de llenado"  
set ylabel "P(p,L)"
set yrange [-0.2: 1.1]
set xrange [0.0: 1.2]
set title " Probabilidad de que aparezca un cluster percolante en función de P y L"
plot "datos32.txt" u 1:2 w l lw 2 t "L = 32", "datos64.txt" u 1:2 w l lw 2 t "L = 64", "datos128.txt" u 1:2 w l lw 2 t "L = 128", "datos256.txt" u 1:2 w l lw 2 t "L = 256"
# plot "datos32.txt" u 1:2:3 w yerrorlines lw 2 t "L = 32", "datos64.txt" u 1:2:3 w yerrorlines lw 2 t "L = 64", "datos128.txt" u 1:2:3 w yerrorlines lw 2 t "L = 128", "datos256.txt" u 1:2:3 w yerrorlines lw 2 t "L = 256"