## 🌍HELLO WORLD!
### ツールをインストールしよう！
- [各種ツールのインストールについて](https://github.com/ro-2020/ev3/wiki/各種ツールのインストールについて)

### 以下のコマンドを実行しよう！
```
$ make init
```

## 🐳BUILD
以下のコマンドを実行すると、EV3で動作するバイナリが`releases`ディレクトリに`app`という名前で生成されます。
```
$ make build
```

生成されるバイナリの名前は変更可能です。たとえば`ryuji`という名前にしたい場合、以下のように環境変数`APP_NAME`を指定してください。
```
$ make build APP_NAME=ryuji
```

## 📕MORE
wikiを見てください。
