# Anet A8 PLUS Dual Color Rebuild

Jako základ pro dvoubarevný tisk jsem zvolil Anet A8Plus, která vypadala jako solidní základ pro předělávku. Později se ukázalo, že to nebyla nejšťastnější volba, ale tiskárna už byla doma, takže jsem si s tím musel poradit.

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
- Deska SKR V1.3
- 5x TMC 2208
- Motor extruderu
- Dlouhé kabely k motorům
- Trianglelab 3D Touch
- 12864 LCD displej se čtečkou karet
- Stepdowny na 12V
- 5015 ventilátor Sunon 12V - ofuk výtisku
- 4010 ventilátor Sunon 12V - hotend
- 6015 ventilátor Sunon 12V - do zdroje
- 50x50 tichý ventilátor Sillentium PC 12V - ofuk desky
- Přívodní kabely průměr 4mm ze zdroje k desce
- Konektory pro připojení endstopů a další kabeláže do desky (XH2.54 2 Pin)
- Konektory pro spojení kabeláže hotendu

### Hardware
- Titan Extruder
- V6 hotend 4.1 bore
- Silikonový návlek na hotend
- Trianglelab TL-Feeder ("joiner" - Y spojka)
- PTFE (ačkoliv jsou dodané k joineru, dával jsem jiné)
- Distanční sloupky k bedu
- Pevné spojky závitové tyče a motoru 5x8mm
- Ložisko LM8UU (vozík osy x)
- Šrouby M4 různých délek
- Stahovací pásky
- Matky do profilů M4

### Tištěné díly

Viz seznam dílů [ve složce STL](https://github.com/PavelTajdus/Anet-A8-PLUS-Dual-Color-Rebuild/tree/master/STL).
