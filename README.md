EV3開発頑張ろうな。

## 🐳BUILD DOCUMENTATION🐳
⚠️プロジェクトのルートディレクトリでコマンドを実行してください。
⚠️GitBash を使ってください！！

- 実行するコマンド
```
./build.sh
```

これでproductionディレクトリにバイナリが生成されます。

## プレフィックスを`app`から`iikanji_app`に変更したい場合
```
./build.sh iikanji_app
```

## キャリブレーションとスタートのやりかた
1. 実行ファイルを選択する
2. キャリブレーションモードになる
>画面表示の通り、黒、白、青の順でキャリブレーションを行う
>キャリブレーションは、取得したい色の上にカラーセンサーを置き、ボタンを押す。
>黒、白、青の後に、自動で尻尾が次の角度に動く。
>これを３回繰り返すと、尻尾がスタートポジションになる。
3. スタートポジションに走行体を置く（カラーセンサーが線にまっすぐ乗るぐらいが理想。この時走行体は線と平行に置くこと）
4. Bluetooth又はボタンでスタート（Bluetoothスタートについては、ArduinoIDEのシリアルモニタより「1」を送信することで可能）
5. 万が一スタートに失敗した場合は、ボタンを押すことで4に戻ることができる（キャリブレーションはやらなくていい）
