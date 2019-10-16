#include "gtest/gtest.h"
#include "../src/Diccionario.h"

#if EJ >= 4
TEST(diccionario, ej4_def) {
	Diccionario d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
}

TEST(diccionario, ej4_obtener) {
	Diccionario d;
	d.definir(1, 4);
	ASSERT_EQ(d.obtener(1), 4);
	d.definir(1, 44);
	ASSERT_EQ(d.obtener(1), 44);
	d.definir(2, 5);
	ASSERT_EQ(d.obtener(1), 44);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(1, 444);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 5);
	d.definir(2, 55);
	ASSERT_EQ(d.obtener(1), 444);
	ASSERT_EQ(d.obtener(2), 55);
}
#endif

#if EJ >= 5

// Completar para el ejercicio 5
TEST(diccionario, ej5_borrar){
    Diccionario d;
    d.definir(1,4);
    d.borrar(1);
    ASSERT_FALSE(d.def(1));
    d.definir(1,2);
    d.definir(2,4);
    d.definir(3,8);
    d.borrar(2);
    ASSERT_FALSE(d.def(2));
    ASSERT_TRUE(d.def(1));
    ASSERT_TRUE(d.def(3));
    d.definir(1,2);
    d.definir(2,4);
    d.definir(3,8);
    d.borrar(4);
    ASSERT_TRUE(d.def(1));
    ASSERT_TRUE(d.def(2));
    ASSERT_TRUE(d.def(3));
}

#endif

#if EJ >= 6

// Completar para el ejercicio 6

#endif

#if EJ >= 7

// Completar para el ejercicio 7
TEST(diccionario, ej7_operadorigualigual){
    Diccionario d1,d2,d3;

    d1.definir(1,2);
    d1.definir(2,4);
    d1.definir(3,8);

    d2.definir(2,4);
    d2.definir(3,8);
    d2.definir(1,2);

    d3.definir(2,4);
    d3.definir(3,7);
    d3.definir(1,2);

    ASSERT_TRUE(d1==d2);
    ASSERT_TRUE(d2==d1);
    ASSERT_FALSE(d1==d3);

}


#endif

#if EJ >= 8

TEST(diccionario, ej8_union){
    Diccionario d1,d2,d3, d_union, d_inter;

    d1.definir(1,2);
    d1.definir(2,4);
    d1.definir(3,8);

    d2.definir(2,4);
    d2.definir(3,8);
    d2.definir(1,2);

    d3.definir(2,4);
    d3.definir(3,7);
    d3.definir(1,2);
    d3.definir(4,16);
    d3.definir(5,32);
    d3.definir(6,64);

    d_union.definir(1,2);
    d_union.definir(2,4);
    d_union.definir(3,8);
    d_union.definir(4,16);
    d_union.definir(5,32);
    d_union.definir(6,64);

    ASSERT_TRUE(d_union == (d1||d3));
    ASSERT_FALSE(d_union == (d3||d1));
}

TEST(diccionario, ej8_interseccion){
    Diccionario d1,d2,d3, d_union, d_inter;

    d1.definir(1,2);
    d1.definir(2,4);
    d1.definir(3,8);

    d2.definir(2,4);
    d2.definir(3,8);
    d2.definir(1,2);

    d3.definir(2,4);
    d3.definir(3,7);
    d3.definir(1,2);
    d3.definir(4,16);
    d3.definir(5,32);
    d3.definir(6,64);

    d_inter.definir(1,2);
    d_inter.definir(2,4);
    d_inter.definir(3,8);

    ASSERT_TRUE(d_inter == (d1&&d3));
    ASSERT_FALSE(d_inter == (d3&&d1));
}
#endif

