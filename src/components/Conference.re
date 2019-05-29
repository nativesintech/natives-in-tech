open Helpers;
open Shared;

[@bs.module]
external checkmark: string = "../../../../public/images/checkmark.svg";

module Styles = {
  open Css;

  let container = style(Styles.container);

  let content = style(Styles.content);

  let header1 = style(Font.size(Title1));

  let header2 = style(Font.size(Title2));

  let text = style(Font.size(Text));

  let points =
    style([
      display(`flex),
      alignItems(`center),
      marginLeft(Spacer.px016),
      lineHeight(`abs(1.25)),
      ...Font.size(Text),
    ]);

  let icon =
    style([
      width(px(30)),
      height(px(30)),
      marginRight(Spacer.px012),
      Styles.mobile([width(px(20)), height(px(20))]),
    ]);

  let link = style([textDecoration(`underline)]);
};

[@react.component]
let make = () => {
  <div>
    <BsReactHelmet>
      <title> "Natives in Tech Conf"->text </title>
      <meta
        name="description"
        content="Information about Natives in Tech Conf"
      />
      <meta
        name="keywords"
        content="natives in tech, natives, indigenous, tech, software development, open source, conference"
      />
      <meta name="twitter:title" content="Natives in Tech Conference" />
      <meta
        name="twitter:description"
        content="Information about Natives in Tech Conf"
      />
      <meta property="og:title" content="Natives in Tech Conference" />
      <meta
        property="og:description"
        content="Information about Natives in Tech Conf"
      />
      <meta
        property="og:url"
        content="https://nativesintech.org/conference/"
      />
    </BsReactHelmet>
    <Frame>
      <div className=Styles.container>
        <div className=Styles.content>
          <h1 className=Styles.header1> {j|Natives in Tech Conf|j}->text </h1>
          <h2 className=Styles.header2>
            {j|November 9th , 2019 - Location TBD|j}->text
          </h2>
          <p className=Styles.text>
            "The Natives in Tech Conference brings together Native and non-Native developers to share projects that empower and support Native communties around the world."
            ->text
          </p>
          <p className=Styles.text>
            "Natives in Tech seeks to encourage Native communties to use software development as a means to empower themselves while encoding a traditional worldview. "
            ->text
          </p>
          <h2 className=Styles.header2>
            "Who is this conference for?"->text
          </h2>
          <p className=Styles.points>
            <img className=Styles.icon src=checkmark />
            "Natives working in software development"->text
          </p>
          <p className=Styles.points>
            <img className=Styles.icon src=checkmark />
            "Non-Natives developing software that empowers Native peoples"
            ->text
          </p>
          <p className=Styles.points>
            <img className=Styles.icon src=checkmark />
            "Individuals and organzations seeking to engage, learn about, and support Native communities"
            ->text
          </p>
          <h2 className=Styles.header2>
            "Would you like to present?"->text
          </h2>
          <p className=Styles.text>
            "If you would like to present at this conference, create a session using "
            ->text
            <a
              className=Styles.link
              href="https://sessionize.com/natives-in-tech/"
              target="_blank"
              rel="noopener noreferrer">
              "sessionize"->text
            </a>
            "."->text
          </p>
          <h2 className=Styles.header2> "Would you like to attend?"->text </h2>
          <p className=Styles.text>
            {j|Stay up to date on all the latest details by joining our mailing list.|j}
            ->text
          </p>
          <SubscribeForm />
          <h2
            style={ReactDOMRe.Style.make(~margin="24px 0 24px 0", ())}
            className=Styles.header2>
            "Conferences"->text
          </h2>
          <p className=Styles.text> "A list of conferences by year"->text </p>
          <div style={ReactDOMRe.Style.make(~marginBottom="48px", ())}>
            <PhenomicPresetReactApp.Link
              href="/conference/2019/" className=Styles.text>
              "2019"->text
            </PhenomicPresetReactApp.Link>
          </div>
        </div>
      </div>
    </Frame>
  </div>;
};
