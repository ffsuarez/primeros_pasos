/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Main example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Main example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 * ENP          Eric Pernia
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 2016-04-26   v0.0.1   First version
 */

/*==================[inclusions]=============================================*/

#include "main.h"         /* <= own header */

#include "sAPI.h"         /* <= sAPI header */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */

 /* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void)
{
   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* Inicializar DigitalIO */
   digitalConfig( 0, ENABLE_DIGITAL_IO);

   /* Configuración de pines de entrada para
	   Teclas de la CIAA-NXP */
   digitalConfig( TEC1, INPUT );
   digitalConfig( TEC2, INPUT );
   digitalConfig( TEC3, INPUT );
   digitalConfig( TEC4, INPUT );
   /* DESDE MAPA DE PERIFERICOS   GPIO0 = DIO32*/
   digitalConfig( DIO32, INPUT_PULLUP ); //PARA CONECTAR CON PULLUP..segun facu es mas interesante
   /* Configuración de pines de salida para
	   Leds de la CIAA-NXP */
   digitalConfig( LEDR, OUTPUT );
   digitalConfig( LEDG, OUTPUT );
   digitalConfig( LEDB, OUTPUT );
   digitalConfig( LED1, OUTPUT );
   digitalConfig( LED2, OUTPUT );
   digitalConfig( LED3, OUTPUT );

   /* Variable para almacenar el valor de tecla leido */
   bool_t valor;

   /* ------------- REPETIR POR SIEMPRE ------------- */
	while(1) {
/*		int i=0;
      valor = !digitalRead( TEC1 );
		digitalWrite( LEDR, valor );
		//ACA PONGO ALGO DE LA LIBRERIA PARA MIRAR
		/*	bool_t digitalWrite( int8_t pin, bool_t value ){

   	   	   	   	   bool_t ret_val     = 1;  //desconozco la razon de esta linea

   	   	   	   	   int8_t pinNamePort = 0;  //declaracion de un nombre de puerto del pin
   	   	   	   	   int8_t pinNamePin  = 0;  //declaracion del nombre del pin

   	   	   	   	   int8_t func        = 0; //declaracion de func

   	   	   	   	   int8_t gpioPort    = 0;  //puerto gpio
   	   	   	   	   int8_t gpioPin     = 0;  //pin gpio

   	   	   	   	   //A CONTINUACION UNA FUNCION "OBTENER CONFIG DE PIN DIGITAL"
					------------------------------------------------------------------
					static void digitalObtainPinConfig( int8_t pin, int8_t config,
                      int8_t *pinNamePort, int8_t *pinNamePin, int8_t *func,
                      int8_t *gpioPort, int8_t *gpioPin ){

						 *pinNamePort = digitalPinsConfig[pin].pinName.port;
						 *pinNamePin  = digitalPinsConfig[pin].pinName.pin;
						 *func        = digitalPinsConfig[pin].func;
						 *gpioPort    = digitalPinsConfig[pin].gpio.port;
						 *gpioPin     = digitalPinsConfig[pin].gpio.pin;
						}
					------------------------------------------------------------------
   	   	   	   	   digitalObtainPinConfig( pin, OUTPUT, &pinNamePort, &pinNamePin, &func,
                           	   	   	   	   &gpioPort, &gpioPin );

   	   	   	   	   Chip_GPIO_SetPinState( LPC_GPIO_PORT, gpioPort, gpioPin, value);

   	   	   	   	   return ret_val;    //ES UN BOOLEANO QUE RETORNA TRUE O FALSE?
			}
		 *
		 */
/*	   valor = !digitalRead( TEC2 );
	   digitalWrite( LED1, valor );
	   digitalWrite( LEDG, valor );

      valor = !digitalRead( TEC3 );
		digitalWrite( LED2, valor );

      valor = !digitalRead( TEC4 );
		digitalWrite( LED3, valor );
		if ((valor=!digitalRead(TEC2))== OFF){  //no estoy seguro del uno
			i++;
		}
		if (i==10){
			digitalWrite( LED2, OFF);
		}*/
		while((digitalRead(TEC1)==OFF)&&(digitalRead(TEC2)==OFF)){
			digitalWrite( LEDB, ON);
			digitalWrite( LED1, ON);
		}
		while((digitalRead(TEC3)==OFF)&&(digitalRead(TEC4)==OFF)){
					digitalWrite( LED2, ON);
					digitalWrite( LED3, ON);
		}
		digitalWrite( LEDB, OFF);
		digitalWrite( LED1, OFF);
		digitalWrite( LED2, OFF);
		digitalWrite( LED3, OFF);
}

	/* NO DEBE LLEGAR NUNCA AQUI, debido a que a este
	   programa no es llamado por ningun S.O. */
	return 0 ;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/