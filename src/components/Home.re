open Helpers;

[@bs.module]
external logo: string = "../../../../public/images/natives-in-tech-logo.png";

[@bs.module]
external slack: string = "../../../../public/images/slack-logo.svg";

[@bs.module]
external github: string = "../../../../public/images/github-logo.svg";

[@bs.module]
external medium: string = "../../../../public/images/medium-logo.svg";

[@bs.module]
external twitter: string = "../../../../public/images/twitter-logo.svg";

[@bs.module]
external folk: string = "../../../../public/images/folk-pattern-black.png";

[@bs.module]
external frame: string = "../../../../public/images/native-land-image.png";

module Styles = {
  open Css;

  let container = style([margin2(~h=auto, ~v=px(0)), position(`relative)]);

  let containerBox =
    style([
      maxWidth(em(50.0)),
      position(`relative),
      padding2(~h=Space.px64, ~v=px(0)),
      media("(max-width: 600px)", [padding2(~h=Space.px24, ~v=px(0))]),
    ]);

  let header =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      alignItems(`center),
      padding2(~h=Space.px64, ~v=px(0)),
      minHeight(Space.px96),
      media("(max-width: 600px)", [padding2(~h=Space.px24, ~v=px(0))]),
    ]);

  let logo = style([display(`flex), alignItems(`center)]);

  let logoName = style([media("(max-width: 600px)", [display(`none)])]);

  let svg = style([marginRight(px(10))]);

  let linksBox =
    style([
      display(`flex),
      selector("> a:not(:last-child)", [marginRight(px(10))]),
    ]);

  let billboard =
    style([
      minHeight(Space.px384),
      Font.font60,
      color(Colors.gray50),
      display(`flex),
      justifyContent(`spaceAround),
      alignItems(`center),
      backgroundColor(Colors.gray900),
      selector("> div", [flex(1)]),
      padding2(~h=Space.px64, ~v=px(0)),
      media("(max-width: 900px)", [flexDirection(`column)]),
      media("(max-width: 600px)", [padding2(~h=Space.px24, ~v=px(0))]),
    ]);

  let billboardHeadline =
    style([
      media(
        "(max-width: 900px)",
        [textAlign(`center), Font.font48, paddingTop(Space.px48)],
      ),
      media(
        "(max-width: 600px)",
        [
          display(`flex),
          alignItems(`center),
          justifyContent(`center),
          paddingTop(Space.px32),
        ],
      ),
      media("(max-width: 410px)", [paddingBottom(Space.px32)]),
    ]);

  let frameBox =
    style([
      display(`flex),
      justifyContent(`center),
      alignItems(`center),
      media(
        "(max-width: 900px)",
        [paddingTop(Space.px48), paddingBottom(Space.px48)],
      ),
      media("(max-width: 410px)", [display(`none), padding(px(0))]),
    ]);

  let frame = style([flex(1), maxWidth(px(400)), alignSelf(`flexEnd)]);

  let content = style([Font.font24]);

  let connect =
    style([
      padding2(~v=Space.px128, ~h=Space.px64),
      backgroundColor(hex("222")),
      color(hex("fff")),
      selector("> h2", [margin(px(0)), Font.font48]),
      media(
        "(max-width: 600px)",
        [padding2(~h=Space.px24, ~v=Space.px128)],
      ),
    ]);

  let connectHeadline =
    style([
      color(hex("fff")),
      textAlign(`center),
      paddingBottom(Space.px64),
    ]);

  let about =
    style([
      position(`relative),
      paddingTop(Space.px64),
      paddingBottom(Space.px128),
      media(
        "(max-width: 600px)",
        [paddingTop(Space.px48), paddingBottom(Space.px64)],
      ),
    ]);

  let iconsBox =
    style([
      margin2(~v=px(0), ~h=`auto),
      display(`flex),
      justifyContent(`spaceBetween),
      alignItems(`center),
      flexWrap(`wrap),
      maxWidth(px(800)),
      media(
        "(max-width: 600px)",
        [
          flexDirection(`column),
          selector("> a:not(:last-child)", [paddingBottom(Space.px48)]),
        ],
      ),
    ]);

  let icon =
    style([
      width(px(100)),
      height(px(100)),
      transition(~duration=200, ~timingFunction=`easeInOut, "transform"),
      selector(
        "&:hover",
        [
          transform(scale(1.5, 1.5)),
          transition(~duration=200, ~timingFunction=`easeInOut, "transform"),
        ],
      ),
      media("(max-width: 600px)", [width(px(75)), height(px(75))]),
    ]);

  let inputs =
    style([
      display(`flex),
      selector("div:not(:last-child)", [marginRight(px(20))]),
      flexWrap(`wrap),
      media(
        "(max-width: 633px)",
        [selector("div:not(:last-child)", [marginRight(px(0))])],
      ),
    ]);

  let inputBox =
    style([
      display(`flex),
      flexDirection(`column),
      marginBottom(Space.px12),
      flex(1),
    ]);

  let input =
    style([
      borderRadius(px(2)),
      border(px(0), `none, `transparent),
      Font.font18,
      padding(Space.px8),
      color(Colors.gray900),
      boxShadow(
        ~x=px(0),
        ~y=px(0),
        ~spread=px(1),
        ~blur=px(1),
        Colors.gray300,
      ),
    ]);

  let textarea =
    style([
      borderRadius(px(2)),
      Font.font18,
      padding(Space.px8),
      minHeight(Space.px128),
      selector("&:invalid", [boxShadow(`transparent)]),
    ]);

  let footer =
    style([
      backgroundColor(Colors.gray900),
      color(Colors.gray50),
      textAlign(`center),
      minHeight(Space.px64),
      display(`flex),
      justifyContent(`center),
      alignItems(`center),
    ]);

  let buttonColor = Colors.redA200;

  let button =
    style([
      Font.font18,
      border(px(2), `solid, buttonColor),
      textTransform(`uppercase),
      padding2(~h=Space.px32, ~v=Space.px12),
      borderRadius(px(3)),
      backgroundColor(buttonColor),
      fontWeight(`bold),
      cursor(`pointer),
      color(Colors.gray50),
      selector(
        "&:hover",
        [
          backgroundColor(Colors.gray50),
          color(buttonColor),
          transition(~duration=200, ~timingFunction=`easeInOut, "color"),
          transition(
            ~duration=200,
            ~timingFunction=`easeInOut,
            "background-color",
          ),
        ],
      ),
    ]);

  let topography =
    style([
      width(px(750)),
      height(px(400)),
      position(`absolute),
      right(px(0)),
      top(px(60)),
      zIndex(-1),
    ]);

  let contact =
    style([
      padding2(~v=Space.px96, ~h=Space.px64),
      maxWidth(em(50.0)),
      media("(max-width: 600px)", [padding2(~h=Space.px24, ~v=Space.px32)]),
    ]);
};

let component = ReasonReact.statelessComponent("Home");

let make = () => {
  ...component,
  didMount: _self => {
    let _ =
      Typing.make(
        "#typing",
        Typing.options(
          ~strings=
            Belt.Array.map(
              [|"Hello", {j|s@^gaêl'A|j}, "Hesci", {j|Yá'át'ééh|j}|], x =>
              x ++ "!"
            ),
          ~typeSpeed=70,
          ~backSpeed=50,
          ~loop=true,
          ~backDelay=500,
          (),
        ),
      );
    ();
  },
  render: _self => {
    let topography = Styles.topography;
    let connect = Styles.connect;
    let billboard = Styles.billboard;
    <div>
      <BsReactHelmet> <title> "Natives in Tech"->text </title> </BsReactHelmet>
      <div className=Styles.container>
        <div className=Styles.header>
          <div className=Styles.logo>
            <img className=Styles.svg src=logo width="50px" height="50px" />
            <h1 className=Styles.logoName> "Natives in Tech"->text </h1>
          </div>
          <div className=Styles.linksBox>
            <a href="#about"> "About"->text </a>
            <a href="#connect"> "Connect"->text </a>
            <a href="#contact"> "Contact"->text </a>
          </div>
        </div>
      </div>
      <div className={j|$billboard |j}>
        <div className=Styles.billboardHeadline>
          {j|Supporting software developers serving Native communities|j}->text
        </div>
        <div className=Styles.frameBox>
          <div className=Styles.frame>
            <div className="screenshot-safari" />
            <img width="100%" height="auto" src=frame />
          </div>
        </div>
      </div>
      <div id="about" className=Styles.about>
        <div className=Styles.containerBox>
          <h2> <span id="typing" /> </h2>
          <p className=Styles.content>
            {j|Welcome 👋. |j}->text
            <strong>
              "Natives in Tech is a coalition of Native and non-Native software developers whose goal is to support
            software application development that reinforces Native beliefs, knowledge, and identity. "
              ->text
            </strong>
            "This is
            achieved through several initiatives: creating a strong social media presence on platforms familiar to software developers,
            hosting a yearly Natives in Tech conference, and building open source software that Native peoples can use to cultivate
            healthy online communities."
            ->text
          </p>
        </div>
        <div className={j|topography $topography|j} />
      </div>
      <div id="connect" className={j|$connect circuit-board |j}>
        <h2 className=Styles.connectHeadline>
          {j|Connect with us 🙌|j}->text
        </h2>
        <div className=Styles.iconsBox>
          <a
            href="https://nativesintech.herokuapp.com/"
            target="_blank"
            rel="noopener noreferrer">
            <img src=slack className=Styles.icon />
          </a>
          <a
            href="https://medium.com/natives-in-tech"
            target="_blank"
            rel="noopener noreferrer">
            <img src=medium className=Styles.icon />
          </a>
          <a
            href="https://github.com/nativesintech"
            target="_blank"
            rel="noopener noreferrer">
            <img src=github className=Styles.icon />
          </a>
          <a
            href="https://twitter.com/nativesintech"
            target="_blank"
            rel="noopener noreferrer">
            <img src=twitter className=Styles.icon />
          </a>
        </div>
      </div>
      <div id="contact" className=Styles.contact>
        <h2> {j|Ask a question or leave a comment 💬|j}->text </h2>
        <p>
          "We would love to hear from you! Feel free to send a message to "
          ->text
          <a href="mailto:hello@nativesintech.app">
            "hello@nativesintech.app"->text
          </a>
          {j| or drop us a line below.|j}->text
        </p>
        <form
          action="https://formspree.io/hello@nativesintech.app" method="POST">
          <div className=Styles.inputs>
            <div className=Styles.inputBox>
              <input
                required=true
                className=Styles.input
                type_="text"
                placeholder="Name"
                name="name"
              />
            </div>
            <div className=Styles.inputBox>
              <input
                required=true
                className=Styles.input
                type_="email"
                placeholder="Email"
                name="_replyto"
              />
            </div>
          </div>
          <div className=Styles.inputBox>
            <textarea
              required=true
              className=Styles.textarea
              placeholder="Message"
              name="message"
            />
          </div>
          <button className=Styles.button type_="submit" value="Send">
            "Submit"->text
          </button>
        </form>
      </div>
      <footer className=Styles.footer>
        {j|Made with ❤️ by Natives in Tech |j}->text
      </footer>
    </div>;
  },
};

let jsComponent = ReasonReact.wrapReasonForJs(~component, _jsProps => make());
