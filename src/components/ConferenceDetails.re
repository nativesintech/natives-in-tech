open Helpers;

module Styles = {
  open Css;

  let billboard =
    style([
      textAlign(`center),
      backgroundColor(Shared.Colors.gray900),
      padding2(~v=Shared.Spacer.px192, ~h=Shared.Spacer.px064),
      marginBottom(Shared.Spacer.px096),
      Shared.Styles.mobile([
        padding2(~v=Shared.Spacer.px128, ~h=Shared.Spacer.px024),
        marginBottom(Shared.Spacer.px064),
      ]),
    ]);

  let container = style(Shared.Styles.container);

  let headline =
    style([
      color(Shared.Colors.gray50),
      ...Shared.Font.size(Shared.Types.Title1),
    ]);

  let tagline =
    style([
      color(Shared.Colors.gray400),
      marginTop(Shared.Spacer.px024),
      ...Shared.Font.size(Shared.Types.Title3),
    ]);

  let header =
    style([
      marginBottom(Shared.Spacer.px064),
      ...Shared.Font.size(Shared.Types.Title2),
    ]);

  let text =
    style([maxWidth(`em(30.0)), ...Shared.Font.size(Shared.Types.Text)]);

  let speaker =
    style([
      display(`flex),
      marginBottom(px(100)),
      Shared.Styles.mobile([flexDirection(`column)]),
    ]);

  let image =
    style([
      borderRadius(px(2)),
      overflow(`hidden),
      minWidth(px(200)),
      maxHeight(px(200)),
      maxWidth(px(200)),
      maxHeight(px(200)),
    ]);

  let details =
    style([
      display(`flex),
      flexDirection(`column),
      paddingLeft(Shared.Spacer.px024),
      Shared.Styles.mobile([padding2(~v=Shared.Spacer.px024, ~h=px(0))]),
    ]);

  let name =
    style([marginBottom(Shared.Spacer.px016), ...Shared.Font.size(Title3)]);

  let session = style([fontWeight(`bold), Shared.FontSize.px18]);

  let bio = style([Shared.FontSize.px20]);
};

[@bs.deriving jsConverter]
type params = {year: string};

type state = {data: option(Types.ConferenceDetails.details)};

type action =
  | UpdateDetails(option(Types.ConferenceDetails.details));

let component = ReasonReact.reducerComponent(__MODULE__);

let make = (~params, _children) => {
  ...component,
  initialState: () => {data: None},
  didMount: self => {
    let {year} = params;
    let id = getIdFromYear(year);

    if (LocalStorage.hasCachedConferenceDetails(year)) {
      let details = LocalStorage.getConferenceDetails(year);
      self.send(UpdateDetails(details));
    } else {
      Js.Promise.(
        Fetch.fetch({j|https://sessionize.com/api/v2/$id/view/speakers|j})
        |> then_(Fetch.Response.text)
        |> then_(text => {
             let result =
               text
               |> Json.parseOrRaise
               |> Decoders.SessionizeAPI.decodeResponse;

             let encodedConferenceData =
               Encoders.LocalStorage.encodeConferenceData(result);

             let result =
               Js.Dict.fromList([
                 ("timestamp", Js.Json.number(getNextDay())),
                 ("data", encodedConferenceData),
               ]);

             LocalStorage.setConferenceDetails(
               year,
               Js.Json.object_(result),
             );

             let details = LocalStorage.getConferenceDetails(year);

             self.send(UpdateDetails(details));

             Js.Promise.resolve();
           })
        |> catch(_e =>
             Js.Exn.raiseError("There were an error in the promise")
           )
      )
      |> ignore;
    };
    ();
  },
  reducer: (action, _state) => {
    switch (action) {
    | UpdateDetails(result) => ReasonReact.Update({data: result})
    };
  },
  render: self => {
    let {year} = params;
    <div>
      <BsReactHelmet>
        <title> {j|Natives in Tech Conf $year|j}->text </title>
        <meta
          name="description"
          content={j|Details about the Natives in Tech Conference|j}
        />
        <meta
          name="keywords"
          content="natives in tech, natives, indigenous, tech, software development, open source, conference"
        />
        <meta name="twitter:title" content={j|Natives in Tech Conf $year|j} />
        <meta
          name="twitter:description"
          content={j|Details about the Natives in Tech Conference of $year|j}
        />
        <meta property="og:title" content={j|Natives in Tech Conf $year|j} />
        <meta
          property="og:description"
          content={j|Details about the Natives in Tech Conference|j}
        />
        <meta
          property="og:url"
          content={j|http://nativesintech.org/conference/$year/|j}
        />
      </BsReactHelmet>
      <Frame>
        <div className=Styles.billboard>
          <h1 className=Styles.headline>
            "Indigenous Peoples in Digital Spaces"->text
          </h1>
          <div className=Styles.tagline> "2019 Conference Details"->text </div>
        </div>
        <div className=Styles.container>
          <h2 className=Styles.header> "Meet the Speakers"->text </h2>
          {switch (self.state.data) {
           | None => "Loading..."->text
           | Some(d) =>
             d.data
             |> List.map((speaker: Types.SessionizeAPI.speaker) => {
                  let firstSessionName =
                    Belt.Option.(
                      Belt.List.head(speaker.sessions)
                      ->map(s => s.name)
                      ->getWithDefault("")
                    );

                  <div className=Styles.speaker>
                    <img className=Styles.image src={speaker.profilePicture} />
                    <div className=Styles.details>
                      <div className=Styles.name> speaker.fullName->text </div>
                      <div className=Styles.session>
                        firstSessionName->text
                      </div>
                      <p className=Styles.bio> speaker.bio->text </p>
                    </div>
                  </div>;
                })
             |> list
           }}
        </div>
      </Frame>
    </div>;
  },
};

type jsProps = {params};

let jsComponent =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~params=paramsFromJs(jsProps##params), [||])
  );
