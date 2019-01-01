open Helpers;

[@bs.module]
external logo: string = "../../../../public/images/natives-in-tech-logo.png";

[@bs.module]
external slack: string = "../../../../public/images/slack-logo.svg";

[@bs.module]
external github: string = "../../../../public/images/github-logo.svg";

[@bs.module]
external medium: string = "../../../../public/images/medium-logo.png";

[@bs.module]
external twitter: string = "../../../../public/images/twitter-logo.svg";

module Styles = {
  open Css;

  let red = style([color(red)]);
  let container = style([margin2(~h=auto, ~v=px(0)), maxWidth(px(900))]);
  let header =
    style([
      display(`flex),
      justifyContent(`spaceBetween),
      alignItems(`center),
    ]);
  let logo = style([display(`flex), alignItems(`center)]);
  let svg = style([marginRight(px(10))]);
  let links =
    style([
      display(`flex),
      selector("> div:not(:last-child)", [marginRight(px(10))]),
    ]);
  let billboard =
    style([
      minHeight(px(400)),
      backgroundColor(black),
      fontSize(px(52)),
      color(white),
      display(`flex),
      justifyContent(`center),
      alignItems(`center),
      textAlign(`center),
    ]);
  let typingContainer = style([maxWidth(px(900))]);
  let typing = style([]);
  let connect = style([textAlign(`center)]);
  let heading = style([padding2(~v=px(30), ~h=px(0))]);
  let icons =
    style([
      display(`flex),
      justifyContent(`spaceAround),
      alignItems(`center),
    ]);
  let icon = style([width(px(70)), height(px(70))]);
};

type state = {empty: string};
type action =
  | NoOp;

let component = ReasonReact.reducerComponent("Home");

let make = () => {
  ...component,
  initialState: () => {empty: ""},
  reducer: (action, _state) => {
    switch (action) {
    | NoOp => ReasonReact.NoUpdate
    };
  },
  didMount: _self => {
    let _ =
      Typing.create(
        "#typing",
        Typing.options(
          ~strings=[|
            "We are Natives in Tech",
            {j|gOtcyathla nAnû, wAchêthlê tOtsûdachE k'asOsOha nôkû|j},
          |],
          ~typeSpeed=50,
          ~backSpeed=50,
          ~loop=true,
          ~backDelay=500,
        ),
      );
    ();
  },
  render: _self =>
    <div>
      <BsReactHelmet> <title> "Natives in Tech"->text </title> </BsReactHelmet>
      <div className=Styles.container>
        <div className=Styles.header>
          <div className=Styles.logo>
            <img className=Styles.svg src=logo width="50px" height="50px" />
            <h1> "Natives in Tech"->text </h1>
          </div>
          <div className=Styles.links>
            <div> "About"->text </div>
            <div> "Conference"->text </div>
            <div> "Contact"->text </div>
          </div>
        </div>
      </div>
      <div className=Styles.billboard>
        <div className=Styles.typingContainer>
          <span id="typing" className=Styles.typing />
        </div>
      </div>
      <div className=Styles.container>
        <h2> "Who we are..."->text </h2>
        <p>
          "Natives in Tech is a coalition of Native and non-Native software developers whose goal is to support and make
          visibile software developers and applications that elevate and reinforce Native beliefs, knowledge, and identity."
          ->text
        </p>
        <h2> "How to get involved..."->text </h2>
        <p>
          "Natives in Tech is seeking volunteers to help with developing applications,
          hosting workshops, speaking at conferences, and generating content that promote Native communities.
          If you would be interested in helping with these initiatives let us know by completing the form below!"
          ->text
        </p>
        <h2> "How we support..."->text </h2>
        <p> "Natives in Tech supports software developers by"->text </p>
        <ul>
          <li> "Engaging developers through online channels"->text </li>
          <li>
            "Building connections with non-Native developers whose work promotes Native communities"
            ->text
          </li>
          <li>
            "Making visible the work of these developers at the Natives in Tech Conference"
            ->text
          </li>
        </ul>
        <div className=Styles.connect>
          <h2 className=Styles.heading> "Connect with Us"->text </h2>
          <div className=Styles.icons>
            <a
              href="https://nativesintech.herokuapp.com/"
              target="_blank"
              rel="noopener noreferrer">
              <img src=slack className=Styles.icon />
            </a>
            <a
              href="https://github.com/nativesintech"
              target="_blank"
              rel="noopener noreferrer">
              <img src=github className=Styles.icon />
            </a>
            <a
              href="https://medium.com/natives-in-tech"
              target="_blank"
              rel="noopener noreferrer">
              <img src=medium className=Styles.icon />
            </a>
            <a
              href="https://twitter.com/nativesintech"
              target="_blank"
              rel="noopener noreferrer">
              <img src=twitter className=Styles.icon />
            </a>
          </div>
        </div>
      </div>
    </div>,
};

let jsComponent = ReasonReact.wrapReasonForJs(~component, _jsProps => make());
