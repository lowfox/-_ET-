EV3開発頑張ろうな。

## 🐳BUILD DOCUMENTATION🐳
⚠️プロジェクトのルートディレクトリでコマンドを実行してください。

⚠️HomeとProで実行するコマンドが違います！！

⚠️`run`する前に`build`してください！！

eオプションを使って、環境変数`EV3_APP_NAME`に`自分の担当セクションの名前を入れることを推奨`します。
たとえば`EV3_APP_NAME=linetrace`として`7/4の12:25:33`にビルドすると、生成されるバイナリの名前が`linetrace0704122533`となります。
なおeオプションを設定しなければ`EV3_APP_NAME=app`として扱われ`app0704122533`となります。

- 実行するコマンド(Home)
```
docker build . -t ev3dev:v1  (初回時、時間かかります！！）
docker run -d -e EV3_APP_NAME=iikanji_name -v $(pwd):/gateway -it ev3dev:v1
```

- 実行するコマンド(Pro)
```
docker build . -t ev3dev:v1  (初回時、時間かかります！！）
docker run -d -e EV3_APP_NAME=iikanji_name -v ev3リポジトリがあるディレクトリのフルパス:/gateway -it ev3dev:v1
```

これでproductionディレクトリにバイナリが生成されます。
