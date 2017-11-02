# TF_Complejidad

## Enemigos:
- **Tipo 1:** recorre todos los casilleros, excepto los que son de pared irrompible.
- **Tipo 2:** solo recorre por aquellos casilleros que están libres.
- Aparece uno de cada tipo por nivel. El enemigo tipo 1 en el extremo opuesto al jugador (m-1, n-1), y el enemigo tipo 2 lo más cerca a la posición de la puerta de salida.
- Si el enemigo llega a una posición en donde ya no tiene casilleros sin visitar para moverse, entonces debera "teletransportarse" al último casillero donde tenía posiciones siguientes sin visitar (BFS)

## Jugador:
- En cada turno, calcula la ruta más corta para llegar a la salida, evitando los casilleros de pared irrompible, y a los enemigos.
- Avanza al siguiente casillero en la ruta calculada y coloca una bomba, luego retorna al casillero diagonal libre mas cercano, si no está disponible, retorna 2 casilleros en linea opuesta a la bomba.
- Una vez que explota la bomba, y desaparece la explosión, el jugador avanza a la última posición visitada (donde colocó la bomba) y vuelve a ejecutar el algoritmo.