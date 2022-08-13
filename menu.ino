void menuPrincipal(){
    digitalWrite(ledGreen,HIGH);
    digitalWrite(ledRed,HIGH);

    cls();

    int i = 0;

    char* menu[] = {
        "BusquedaYdetruir",
        "Sabotaje",
        "Dominacion",
        "Bomb Setup",
    };

    lcd.print(menu[i]);

    lcd.setCursor(15,1);

    checkArrows(i, 2);

    while(1){
        var = teclado.waitForKey();
        if(var == button_Up && i > 0){
            i--;
            cls();
            lcd.print(menu[i]);
            delay(1000);
        }else if(var == button_Down && i < 3){
            ++i;
            cls();
            lcd.print(menu[i]);
            checkArrows(i, 3);
            delay(1000);
        }else if(var == button_Selec){
            cls();
            switch (i)
            {
            case 0:
                sdStatus = true;
                break;
            case 1:
                saStatus = true;
                cls();
                lcd.print("Iniciando");
                lcd.setCursor(0,1);
                lcd.print("B- cancelar");
                break;
            case 2:
                deStatus = true;
            default:
                break;
            }
        }
    }
}