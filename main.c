
// #include <stdarg.h>
// #include <stdio.h>
// int topla(int miktar, ...)
// {
// 	va_list ag;
// 	int i, toplam;

// 	va_start(ag, miktar);
// 	toplam = 0;
// 	for(i = 0; i < miktar; i++)
// 	toplam += va_arg(ag, int); 
// 	return toplam;
// }

// int main()
// {
// 	printf("%d", topla(2, 5, 2));
// }

// #include <stdarg.h>
// #include <stdio.h>
// int main()
// {
// 	// char *str = "Rumeysa_Nur_Akpinar";
// 	// char c = 'a';
// 	// int	hex = 754;
// 	// unsigned int u = 4294967293;
// 	// int i = -4;
// 	// ft_printf("%s\n%d\n%p\n%c\n%x\n%X\n%u\n%%\n%i", str, i, str, c, hex, hex, u, i, i);

// 	// ft_printf("My name is %s and I am %d years old.", "Alice", 25);
// // 	printf("%d", result); 
// }

// int result = ft_printf("My name is %s and I am %d years old.", "Alice", 25);

// Burada, ft_printf fonksiyonu, "My name is %s and I am %d years old." formatında bir çıktı üretecektir. Bu çıktının içinde, %s format belirteci, "Alice" değeriyle değiştirilecek ve %d format belirteci ise 25 değeriyle değiştirilecektir.
// Fonksiyon çağrısı sırasında, va_start fonksiyonu ile "argüman listesi" üzerinde gezinmek için bir "ap" pointer'ı oluşturulacaktır. Bu "ap" pointer'ı, argüman listesindeki ilk değişkenin adresini tutacaktır. Bu örnekte, argüman listesi "Alice" ve 25 değişkenlerinden oluşmaktadır.
// Daha sonra, ft_printf fonksiyonu, while (*str) döngüsü içinde, *str pointer'ının işaret ettiği karakteri kontrol eder. Eğer bu karakter % işareti ise, ft_check fonksiyonu çağrılır ve bu fonksiyona ap pointer'ı da argüman olarak verilir. ft_check fonksiyonu, % işaretinden sonra gelen karaktere göre ilgili değişkenin tipini belirler ve bu tip bilgisini kullanarak argüman listesindeki değeri alır. Bu değeri, % işaretinin yerine yazarak, oluşturulan çıktı stringine ekler.
// Örneğimizde, "My name is " stringi yazdırıldıktan sonra %s format belirteciyle değiştirilecek olan "Alice" stringi, ft_check fonksiyonu ile argüman listesinden alınır ve oluşturulan çıktıya eklenir. Daha sonra, " and I am " stringi yazdırılır ve %d format belirteciyle değiştirilecek olan 25 integer değeri, yine ft_check fonksiyonu ile argüman listesinden alınır ve oluşturulan çıktıya eklenir.
// Bu işlemler sonucunda, "My name is Alice and I am 25 years old." çıktısı oluşur. Bu çıktıda toplamda 33 karakter bulunmaktadır. Bu karakter sayısı, val değişkeninde biriktirilir ve sonuç olarak result değişkenine atanır. Dolayısıyla, result değişkeni 33 değerini alacaktır.
// Bu örnekte, val değişkeni, ft_printf fonksiyonunun içinde bulunan diğer fonksiyonların döndürdüğü karakter sayısının toplamını
// val değişkeni, ft_printf fonksiyonunun içinde bulunan diğer fonksiyonların döndürdüğü karakter sayısının toplamını biriktiren bir değişkendir. ft_check fonksiyonu, ft_putchar fonksiyonu ve diğer yardımcı fonksiyonlar, val değişkeninin değerinin artmasına neden olurlar. Dolayısıyla, ft_printf fonksiyonu tamamlandığında, val değişkeni, oluşturulan çıktının toplam karakter sayısını içerecektir.
// val değişkeni, fonksiyonun sonunda, return anahtar kelimesiyle fonksiyondan döndürülür. Bu sayede, ft_printf fonksiyonunun çağrıldığı yere, oluşturulan çıktının toplam karakter sayısı iletilebilir. Bu sayede, result değişkenine, oluşturulan çıktının toplam karakter sayısı atanarak, sonucun kullanıcıya döndürülmesi sağlanır.