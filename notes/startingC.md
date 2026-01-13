# Serüvenin Başlangıcı

* Temeldeki amacım Node tabanlı, basit bir elektrik devre simülatörü yapmak ve donanım çalıştırmaktı.

* Öncelikle donanımdaki adresleme ve pointer işini çözmem gerekti.

* Bunun için çok kısa bir süre assembly üzerinde registerlarla oynadım.

* ESP32 ile bare metal işlerinin nasıl işlediğini merak ettim. Bu biraz karmaşık geldi

* PIC16F serisi ile biraz bare metal uğraşmak istedim çünkü yazılım ile donanım arasınadaki olayı daha iyi anlayacaktım.

* Bu noktada assembly de fazla soyut geldiği için direkt olarak binary kodlamaya geçtim.

* Bu noktada port geçişlerini ve bir pini giriş ya da çıkış ayarlamak için hangi kapıların 1 ya da 0 yapılması gerektiğini datasheetten okuyarak uyguladım.

* Bu noktada assemblynin kıymetini anladım ve onun gerekliliğine hak verdim. İnsan bir şeyin zorluğunu görmeden kıymetini anlayamazdı.

* Assembly ile de biraz vakit geçirdikten sonra soyutlama yapmanın çok meşakatli iş olduğunu gördüm ve amacım da buydu. Daha sonra C diline nihayet istediğim yerden girebildim.

* Pythondan geldiğim için ilk c ye girdiğim zaman her işi yeniden inşaa etmekte zorlandım.

* C dili de olaya bakışımı biraz daha değiştirdi. Hem soyutlayabilme kapasitesi hem de donanıma olan yakınlığı güzeldi.

* Daha sonra ufkumu açabilecek yeni işler istedim. Belki bir mini dil tasarlamak.

* Öncelikle bunu pythonla biraz denedim 

``` python  

print hello
x 5
y 5
print x*y

```

* tarzında çok basit bir syntaxı yorumladım. Mantığını bir nebze kavramak için

* Daha sonra Lisp fikriyle karşılaştım. Bu fikri sevdim ve Common Lisp ile güzel işler çıkaracağıma inanıyorum.

* Common Lispi elektrik devre simülatöründe doğal dil için kullanacağım. Belki prolog dilini de katarak devrenin mantıklı olup olmadığını işleyebilirim.

* Common Lisp benim için motorun parçalarını veren bir arayüz olacak. 