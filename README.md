*This project has been created as part of the 42 curriculum by mumidill.*

# get_next_line

## Açıklama

`get_next_line`, bir fd`yi tek seferde bir satır okuyan bir C fonksiyonudur.

Fonksiyon her çağrıldığında dosyadan `BUFFER_SIZE` kadar veri okur ve bir sonraki `\n` karakterine kadar olan kısmı döndürür. Kalan veri, çağrılar arasında konumun unutulmaması için **static bir değişkende** saklanır; böylece dosyanın tamamı art arda yapılan çağrılarla satır satır okunabilir.

## Talimatlar
derlerken -D BUFFER_size flagını sisteminnizin gücüne göre ayarlabilirsiniz

Kullanmak için projenize `#include "get_next_line.h"` şeklinde kütüphaneyi eklemeniz gerekir.

### Gereksinimler

get_next_line fonksiyonu derlemek için güncel C derleyicisi gerekmektedir.

### Kullanım Örneği

```c
#include "get_next_line.h"

int main(void)
{
    char *string;
    string = get_next_line(fd);
    return (0);
}
```

## Fonksiyon Detayı

`get_next_line`, okumayı tek bir static değişken üzerinde biriken, büyüyen bir hafıza ile gerçekleştirir

## Kaynaklar

* [get_next_line explained](https://www.youtube.com/watch?v=8E9siq7apUU)
* [C23 Taslakları](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3220.pdf)
* [The C Programming Language kitabı](https://www.columbia.edu/~ng2573/c89/kr2.pdf)

### Yapay Zeka Kullanımı

Yapay zeka, makefile dosyasının düzenlenmesinde kullanılmıştır. README.md dosyasındaki yazım ve imla hataları düzeltilmiştir. kullanılan Fonksiyonların işleyişi hakkında bilgi alınmıştır.