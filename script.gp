set term pdf
set out "Graficas.pdf"
set xlabel "Probabilidad de llenado"  
set ylabel "P(p,L)"  
set title " Probabilidad de que aparezca un cluster percolante en función de P y L"
# plot "datos32.txt" u 1:2 w lp t "L = 32"
plot "datos32.txt" u 1:2:3 w yerrorlines lw 2 t "L = 32"