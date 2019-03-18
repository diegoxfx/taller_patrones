#pragma once

enum {menu_principal, crear, leer, actualizar, borrar, salir,
      crear_factura, crear_cliente, crear_item, crear_tipo_item,
      leer_factura, leer_cliente, leer_item, leer_tipo_item,
      actualizar_factura, actualizar_cliente, actualizar_item, actualizar_tipo_item,
      borrar_factura, borrar_cliente, borrar_item, borrar_tipo_item};
  
void interfaz_consola();
void interfaz_menu_principal(int &estado);
void interfaz_menu_crear(int &estado);
void interfaz_menu_leer(int &estado);
void interfaz_menu_actualizar(int &estado);
void interfaz_menu_borrar(int &estado);

void interfaz_crear_cliente(int &estado);
void interfaz_crear_factura(int &estado);
void interfaz_crear_item(int &estado);
void interfaz_crear_tipo_item(int &estado);

void interfaz_leer_cliente(int &estado);
void interfaz_leer_factura(int &estado);
void interfaz_leer_item(int &estado);
void interfaz_leer_tipo_item(int &estado);

void interfaz_actualizar_cliente(int &estado);
void interfaz_actualizar_factura(int &estado);
void interfaz_actualizar_item(int &estado);
void interfaz_actualizar_tipo_item(int &estado);

void interfaz_borrar_cliente(int &estado);
void interfaz_borrar_factura(int &estado);
void interfaz_borrar_item(int &estado);
void interfaz_borrar_tipo_item(int &estado);
