# Bunny Hop Hack for Counter-Strike: DLL Injection

![Banner](https://steamuserimages-a.akamaihd.net/ugc/198554609101753931/A9C6E97CA2D09FC963C0017D64145505B47451A6/?imw=800&imh=450&ima=fit&impolicy=Letterbox&imcolor=%23000000&letterbox=true)


> **Disclaimer**: Este projeto foi desenvolvido exclusivamente para fins educativos e para estudo de engenharia reversa e injeção de DLLs. NÃO use este projeto em servidores oficiais ou para trapaças online. Qualquer uso malicioso é de sua responsabilidade.

## Sobre o Projeto
Este repositório implementa um hack básico de Bunny Hop para Counter-Strike através de injeção de DLL. O projeto foi criado com base no vídeo [YOUR FIRST INTERNAL - BHOP HACK](https://www.youtube.com/watch?v=Oam-8lVxNq8&list=TLPQMTQxMjIwMjRNx1BGICBU7g&index=5) do cazz, que explica os conceitos fundamentais para este tipo de modificação.

## Requisitos
- [Hazedumper](https://github.com/frk1/hazedumper-rs): Para obter offsets atualizados do Counter-Strike.
- [Xenos Injector](https://www.unknowncheats.me/forum/general-programming-and-reversing/126808-xenos-injector.html): Utilizado para injeção da DLL (apenas para testes). **Nota**: Este injector é facilmente detectado, use-o apenas em ambientes seguros.
- Counter-Strike rodando com o comando de inicialização `-insecure` para evitar problemas em servidores VAC protegidos.

## Como Usar
1. Clone este repositório:
   ```bash
   git clone https://github.com/seuusuario/bunnyhop-hack.git
   ```
2. Baixe os offsets mais recentes utilizando o Hazedumper.
3. Compile o projeto e gere o arquivo `.dll`.
4. Abra o Counter-Strike com o comando `-insecure`:
   - Clique com o botão direito no jogo na sua biblioteca Steam.
   - Escolha **Propriedades** > **Opções de Inicialização** e adicione `-insecure`.
5. Use o Xenos Injector para injetar a DLL no processo do jogo.

## Aviso Legal
O uso deste código em ambientes não autorizados pode violar os Termos de Serviço do Counter-Strike e resultar em banimentos permanentes. O repositório não apoia nem encoraja o uso em servidores públicos ou oficiais.

---

Feito com base no tutorial [YOUR FIRST INTERNAL - BHOP HACK](https://www.youtube.com/watch?v=Oam-8lVxNq8&list=TLPQMTQxMjIwMjRNx1BGICBU7g&index=5) do cazz. Offsets fornecidos pelo [Hazedumper](https://github.com/frk1/hazedumper-rs).

