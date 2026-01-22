

# Adımlarım

* 1 matris işlemlerimi hızlanıran bir modül tasarlamak oldu.
* 2 graf veriy yapısını çözmem gerekiyordu. Ben de nodelar arasındaki bağlantıları matris ile ifade eebileceğim bir program tasarladım

* 3 Elemean ekledim resistor gibi

## Tasarımsal Hatalarım ve Sınırları

* 1 Elemanları node bağlantılarından izole ettiğim için nodedan elemana erişmek imkansızdı. Aslında matriste bilgisini tutmam gereken şey katmanın en tepesinde duran birim olmalıydı. Yani bağlantı matrisini Base class için de oluşturmam gerekiyor.

* 2 C dilinde inheritance kavramının yoksunluğu base class işini zora sokabilir. Her yerden erişilebilir bir değişken tanımlayabilirsem bunu aşabilirim ya da bir h dosyasına static counter oluşturup her eleman eklendiğinde bu sayacı artırıp bu farklı tipteki verileri aynı dizide tutmanın bir yolunu bulmalıyım.

## Bana Kattıkları

* 1 C dili gerçekten çok çok güçlü bir silah fakat bu silahı kendinize sıkmamanız için hiçbir koruma yok.
* 2 C dilini bu kadar özel kılanlardan birisi de donanuma oldukça yakın olup harika soyutlama yapabilmesi.
* 3 Bu işe bir dil nazarında bakmaktan ziyade bir ekosistem olarak görmek daha faydalı oldu. 
* 4 Assembly/PIC16F serisine girmem gerekti çünkü yazılım-donanım köprüsünü anlamak istedim.

### Sonuç:

Sonuç olarak C dili ile farklı düşünce biçimi geliştirmeye başladım. Bana göre bir dil olduğunu fark ettim. Oldukça yalın ürünlerden hoşlanıyorum mümkün mertebe düşük imkanlarla sınırları zorlamayı seviyorum. Bu sebeple low level işlerden biraz daha zevk alıyorum. 