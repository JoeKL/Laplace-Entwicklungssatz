# Laplace-Entwicklungssatz
Hier ein mal ein Laplace-Entwicklungssatz mit dazugehörigen Laufzeittests mit jeweils einer 3x3, 4x4, 5x5 und 6x6 Matrix.<p/>

### Prototyping in Visual Studio mit C<br/>
Die Laufzeiten auf meinem Rechner:<br/>
  
| dim | func        | reps            | time    |
|-----|-------------|-----------------|---------|
| 3x3 |     Laplace | 1.000.000 execs |    37ms |
| 4x4 |     Laplace | 1.000.000 execs |  1317ms |
| 5x5 |     Laplace |   100.000 execs |   831ms |
| 6x6 |     Laplace |    10.000 execs |   521ms |

<p>

Compiled mit Visual Studio 15.9.2 - Debug - 32 Bit<br>
<br>
<br>
<br>
  
### Octave Anbindung via .mex-File und Gegenüberstellung mit Octaves det()-Funktion
<p>
 <img src="https://github.com/JoeKL/Laplace-Entwicklungssatz/blob/master/LaPlace%20Entwicklungssatz/mex/ggue.png" height="500"> 
<p>
Die Laufzeit in Gegenüberstellung mit der det()-Funktion von Octave (ROT) hat ergeben, dass die rekursive Laplace-Entwicklung (BLAU) bis 5x5 um einiges schneller ist. Bei einer Matrize von 6x6 leigen beider Algorithmen gleich auf. Ab einer Matrize größer als 6x6 ist die det()-Funktion von Octave schneller.
<p>
Dadurch, dass unser gegebenes Problem aber nur eine 5x5 Matrix ist, ist die Nutzung der Laplace-Entwicklung sinnvoller.
<br>
<br>
<br>
<br>

Mein System:<br>
  Systemmodell: Dell XPS 15 9560<br>
  OS: Windows 10 Home 64-Bit-Version (10.0, Build 17763)<br>
  CPU: Intel Core i5 7300HQ @ 2.50GHz (4 CPUs)<br>
  Speicher: 8192MB RAM
