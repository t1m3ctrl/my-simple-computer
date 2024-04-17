# Очищаем экран
echo -e "\E[H\E[J"

# Переходим в альтернативный символьный набор
# echo -e "\033(0``aaffggjjkkllmmnnooppqqrrssttuuvvwwxxyyzz{{||}}~~"
#                  ▒▒°°±±┘┘┐┐┌┌└└┼┼⎺⎺⎻⎻──⎼⎼⎽⎽├├┤┤┴┴┬┬││≤≤≥≥ππ≠≠££··
# Выводим число - 7
echo -e "\033(0"
echo -e "\E[10;5Hlqqqqqqqqk"
echo -e "\E[11;5Hxaaaaaaaax"
echo -e "\E[12;5Hx      aax"
echo -e "\E[13;5Hx      aax"
echo -e "\E[14;5Hx      aax"
echo -e "\E[15;5Hx      aax"
echo -e "\E[16;5Hx      aax"
echo -e "\E[17;5Hmqqqqqqqqj"

# Возвращаемся из альтернативного символьного набора
echo -e "\033(B"

# Перемещаем курсор
echo -e "\E[19;0H"