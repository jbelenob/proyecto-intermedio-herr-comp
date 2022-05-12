set term pdf
set out "Tamaño_de_cluster2.pdf"
set xlabel "Probabilidad de llenado"  
set ylabel "s(p,L)"
# set yrange [-0.2: 1.1]
# set xrange [0.0: 1.2]
set title " Tamaño promedio del cluster percolante más grande en función de p y L"
set key left top
#plot "datos_size32.txt" u 2:3 w l lw 2 t "L = 32", "datos_size64.txt" u 2:3 w l lw 2 t "L = 64", "datos_size128.txt" u 2:3 w l lw 2 t "L = 128", "datos_size256.txt" u 2:3 w l lw 2 t "L = 256", "datos_size512.txt" u 2:3 w l lw 2 t "L = 512"
plot "datos_size32.txt" u 2:3:4 w yerrorlines lw 2 t "L = 32", "datos_size64.txt" u 2:3:4 w yerrorlines lw 2 t "L = 64", "datos_size128.txt" u 2:3:4 w yerrorlines lw 2 t "L = 128", "datos_size256.txt" u 2:3:4 w yerrorlines lw 2 t "L = 256", "datos_size512.txt" u 2:3:4 w yerrorlines lw 2 t "L = 512"
# plot "datos32.txt" u 1:2 w l lw 2 t "L = 32", "datos64.txt" u 1:2 w l lw 2 t "L = 64", "datos128.txt" u 1:2 w l lw 2 t "L = 128", "datos256.txt" u 1:2 w l lw 2 t "L = 256"
# plot "datos32.txt" u 1:2:3 w yerrorlines lw 2 t "L = 32", "datos64.txt" u 1:2:3 w yerrorlines lw 2 t "L = 64", "datos128.txt" u 1:2:3 w yerrorlines lw 2 t "L = 128", "datos256.txt" u 1:2:3 w yerrorlines lw 2 t "L = 256"