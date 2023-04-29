#!/usr/bin/awk -f

BEGIN{
	FS=" ";
	numero_particulas=0;
	velocidad=0;
}
(NR>9){
	velocidad+=sqrt($6^2+$7^2+$8^2);
        numero_particulas++;
}

END{
	print "La velocidad promedio es: ", velocidad/numero_particulas;
}
