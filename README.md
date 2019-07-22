# Anet A8 PLUS Dual Color Rebuild

Kamarád chtěl postavit dual color tiskárnu. Jako základ pro dvoubarevný tisk jsem zvolil Anet A8Plus, která vypadala jako solidní základ pro předělávku. Později se ukázalo, že to nebyla nejšťastnější volba, ale tiskárna už byla doma, takže jsem si s tím musel poradit.

Protože tiskárna z výroby není moc dobře udělaná (profily nemají stejné délky - lítá to až o milimetr), závitovky nejsou rovné atd atd, musel jsem trochu přepracovat některé díly. Nakonec jsem toho přepracovával hodně :-)

Z původní tiskárny jsem použil profily, tyče, závitovky, motory, endstopy a pár kabelů. Zbytek jsem předělal.

![PT Anet A8Plus Dual Color](https://github.com/PavelTajdus/Anet-A8-PLUS-Dual-Color-Rebuild/blob/master/Images/cela.jpg?raw=true)

## Dual Color

Jako systém pro dvoubarevný tisk jsem zvolil systém dvou extruderů do jednoho hotendu (Y joiner). Jedná se o relativně jednoduché řešení, které podporuje i mnou používaný Prusa Slicer 2.0.

Použil jsem klona V6 hotendu s bore 4.1 heatbreakem. Používá se proto, aby do hotendu šla tenčí PTFE o průměru 1,9mm, a do "joineru" pak klasická PTFE o průměru 2,0mm. Zabezpečí se tím hladší chod filamentu v "joineru".

## Vyměněné díly

Kvůli použití dvou extruderů jsem musel měnit i desku. Zvolil jsem SKR v1.3, což je 32bitová deska za výbornou cenu. Dokonce levnější než originální Anet deska. Origo deska má integrované drivery, takže jsem k SKR nakoupil 5x TMC2208, které jsem zapojil v UART. Díky tomu se dají drivery ovládat z Firmware a nastavovat jejich mod, hybrid treshold a jiné srandy.

Abych zajistil dostatečně kvalitní podávání filamentu, rozhodl jsem se pro Titan extruder (opět klony). Mám s nimi dobré zkušenosti - dobře se zavádí a vyndavá filament (oproti BMG). A je za super cenu.

Protože jsem nebyl absolutně schopný vyrovnat podložku standardními levlovacími šrouby, rozhodl jsem se pro 3Dtouch. Měl jsem dva různé senzory, jeden od Trianglelab, druhý od Fysetc. Fysetc skončil v koši. Absolutně k ničemu. Trianglelab naštěsti funguje obstojně. Podložku jsem přišrouboval napevno pomocí distančních sloupků.

Další výměna mě čekala u displeje. Nebyl jsem schopný rozhýbat originální přibalený displej, tak jsem použil klasický velký 12864 LCD displej se čtečkou karet. Čtečka karet v displeji je mnohem příjemnější pro obsluhu než lovit malou mikro sd kartu za tiskárnou v desce.

## Seznam dokoupených dílů

### Elektronika
- [Deska SKR V1.3](https://www.aliexpress.com/item/32980090169.html)
- [5x TMC 2208](https://www.aliexpress.com/item/32980090169)
- [Motor extruderu](https://www.aliexpress.com/item/32377416566.html)
- [Dlouhé kabely k motorům](https://www.aliexpress.com/item/33015610522.html)
- [Rozdvojka konektorů pro Z motory](https://www.aliexpress.com/item/32849801852.html)
- [Trianglelab 3D Touch](https://www.aliexpress.com/item/32832887426.html)
- [12864 LCD displej se čtečkou karet](https://www.aliexpress.com/item/32516184695.html)
- [Stepdowny na 12V](https://www.aliexpress.com/item/32725444495.html)
- [5015 ventilátor Sunon 12V - ofuk výtisku](https://www.official.cz/z5376-ventilator-sunon-gb1205phvx-8ay-gn)
- [4010 ventilátor Sunon 12V - hotend](https://www.gme.cz/ventilator-sunon-ee40101s2-1000u-999)
- [6015 ventilátor Sunon 12V - do zdroje](https://www.gme.cz/ventilator-sunon-kd1206phs3)
- [50x50 tichý ventilátor Sillentium PC 12V - ofuk desky](https://www.czc.cz/silentiumpc-zephyr-50-50mm/134487/produkt)
- [Přívodní kabely průměr 4mm ze zdroje k desce](https://www.emat.cz/index.php?route=product/search&search=H07V-K%204)
- [Konektory pro připojení endstopů a další kabeláže do desky (XH2.54 2 Pin)](https://www.aliexpress.com/item/32821493939.html)
- [Konektory pro spojení kabeláže hotendu](https://www.aliexpress.com/item/32843315324.html)

### Hardware
- [Titan Extruder](https://www.aliexpress.com/item/32789942768.html)
- [V6 hotend 4.1 bore](https://www.aliexpress.com/item/32911028903.html)
- [Silikonový návlek na hotend](https://www.aliexpress.com/item/32920518452.html)
- [Trianglelab TL-Feeder ("joiner" - Y spojka)](https://www.aliexpress.com/item/32770576556.html)
- [PTFE (ačkoliv jsou dodané k joineru, dával jsem jiné)](https://www.aliexpress.com/item/32814232529.html)
- [Distanční sloupky k bedu](https://www.gme.cz/distancni-trubicka-mdr4305)
- [Pevné spojky závitové tyče a motoru 5x8mm](https://www.aliexpress.com/item/32957956109.html)
- [Ložisko LM8UU (vozík osy x)](https://www.aliexpress.com/item/32317938156.html)
- [Šrouby M4 různých délek](https://eshop.killich.cz/eshop/nerezovy-spojovaci-material/srouby-zatky/imbusy-vnitrni-sestihran/din-912-imbus-s-valcovou-hlavou/)
- [Stahovací pásky](https://www.aliexpress.com/item/32868074097.html)
- [Matky do profilů M4](https://www.aliexpress.com/item/32799858611.html)

### Tištěné díly

Viz seznam dílů [ve složce STL](https://github.com/PavelTajdus/Anet-A8-PLUS-Dual-Color-Rebuild/tree/master/STL).
