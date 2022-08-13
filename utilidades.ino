void cls(){
    lcd.clear();
    lcd.setCursor(0,0);
}

void checkArrows(byte i, byte max){

    if(i == 0){
        lcd.setCursor(15,1);
        lcd.write(7);
    }

    if(i == max){
        lcd.setCursor(15,0);
        lcd.write(6);
    }
    
    if(i > 0 && i < max){
        lcd.setCursor(15,0);
        lcd.write(6);
        lcd.setCursor(15,1);
        lcd.write(7);
    }
}
