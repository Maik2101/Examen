//Programa hecho por mi :)
#include <stdio.h>
#include <string.h>
//la formulacion de la funcion de login
int login() {
    char nombres[3][20] = {"Maicol","Stefania", "Aileen"};
    char contras[3][20]= {"1721", "2101", "0709"};//declaracion de variables

    char nombre[20];
    char contra[20];
    int intentos = 0;

    while (intentos < 3) {
        printf("Ingrese su usuario: ");
        scanf("%s", nombre);
        printf("Ingrese su contraseña: ");
        scanf("%s", contra);

        int i;
        for (i = 0; i < 3; i++) {
            if (strcmp(nombre, nombres[i]) == 0 && strcmp(contra, contras[i]) == 0) {
                return 1; 
            }
        }

        intentos++;
        printf("Usuario o contraseña fallidos. Intento #%d\n", intentos);
    }

    printf("Imposible ingresar.\n");
    return 0;  // Nombres incorrectas 
}
//realizamos la funcion de la calculacion de precio de la ruta
float calcularPrecioRuta(char tpruta) {
    float pre;
// Realizamos los casos de los tipos de rutas 
    switch (tpruta) {
        case 'U':
            pre = 0.10;
            break;
        case 'I':
            pre = 0.15;
            break;
        case 'Y':
            pre = 0.20;
            break;
        default:
            printf("Tipo de ruta inválido.\n");
            pre = 0.0;
            break;
    }

    return pre;
}
//Realizamos la funcion y con estructuras para calcular el descuento
float calcularDescuento(float pre) {
    float descuento = 0.0;

    if (pre < 50.0) {
        descuento = 0.0;
    } else if (pre >= 50.0 && pre < 100.0) {
        descuento = pre * 0.05;
    } else if (pre >= 100.0 && pre < 500.0) {
        descuento = pre * 0.1;
    } else if (pre >= 500.0) {
        descuento = pre * 0.2;
    }

    return descuento;
}
//Funcion para visualizar el costo, descuento y precio total
void operacionTransporte() {
    int i;
    char tipoRuta;
    float distancia, subtotal, descuento, precioTotal;

    for (i = 0; i < 5; i++) {
        printf("Cliente %d\n", i + 1);
        printf("Ingrese el tipo de ruta (Urbana U, Interurbana I, Internacional Y): ");
        scanf(" %c", &tipoRuta);
        printf("Ingrese la distancia en kilómetros: ");
        scanf("%f", &distancia);
//calculacion
        float precioPorKilometro = calcularPrecioRuta(tipoRuta);
        subtotal = distancia * precioPorKilometro;
        descuento = calcularDescuento(subtotal);
        precioTotal = subtotal - descuento;

        printf("Subtotal: %.2f\n", subtotal);
        printf("Descuento: %.2f\n", descuento);
        printf("Precio Total: %.2f\n",precioTotal);
}
}
//Realizamos funcion de red social donde declaramos y realizamos estructuras para indicar mensajes......*/
void redSocial() {
int i;
char mensaje[100];
char categoria;
int noti = 0, event = 0, ask = 0;
for (i = 0; i < 5; i++) {//realizamos las estrcutras if
    printf("Mensaje %d\n", i + 1);
    printf("Ingrese el contenido del mensaje: ");
    scanf(" %[^\n]", mensaje);
    printf("Ingrese la categoría del mensaje (Noticias [N], Eventos [E], Preguntas [P]): ");
    scanf(" %c", &categoria);

    switch (categoria) {
        case 'N':
            noti++;
            break;
        case 'E':
            event++;
            break;
        case 'P':
            ask++;
            break;
        default:
            printf("Categoría inválida.\n");
            break;
    }
}

printf("Publicaciones:\n");
printf("Noticias: %d\n", noti);
printf("Eventos: %d\n", event);
printf("Preguntas: %d\n", ask);
}
//Funcion para el menu
void menu() {
int opcion;
do {
    printf("\n--- MENU ---\n");
    printf("1. Operacion de transporte\n");
    printf("2. Interactuar en la red social\n");
    printf("3. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            operacionTransporte();
            break;
        case 2:
            redSocial();
            break;
        case 3:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }
} while (opcion != 3);
}

int main() {
printf("--- Sistema de Transporte Publico ---\n");
if (login()) {
    menu();
} else {
    printf("Ingreso incorrecto. Fin del programa.\n");
}

return 0;
}