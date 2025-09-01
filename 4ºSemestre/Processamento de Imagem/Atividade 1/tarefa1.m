entrada = imread("tungsten_filament_shaded.tif");
sombreamento = imread("tungsten_sensor_shading.tif");

imshow(entrada); #imagem "errada"

x = im2double(entrada);
y = im2double(sombreamento);

resultado = x ./ y;

figure, imshow(resultado); #precisa do figure antes para aparecer a primeira imagem e essa com resultado final

#Lembrando que depois de rodar o código com o octave --persist tarefa1.m e entrar no terminal interativo
#Só escrever tarefa1 (sem.m) para rodar novamente, sem precisar sair do terminal 