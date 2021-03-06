import { Header } from "./Header";
import { Footer } from "./Footer";
import { Offline } from "react-detect-offline";
import Link from "next/link";

type Props = {
  children: React.ReactNode;
};

export function Layout(props: Props) {
  return (
    <div className="flex flex-col min-h-screen dark:bg-nit-black bg-nit-white">
      <Offline>
        <div className="p-2 text-center bg-nit-primary dark:text-nit-black text-nit-white">
          You are viewing this site offline. Some images may not render.
        </div>
      </Offline>
      <div className="p-2 text-center bg-nit-primary dark:text-nit-black text-nit-white">
        Natives in Tech Conf 2021 is just around the corner!{" "}
        <Link href="/conference/2021" passHref>
          <a href="" className="underline">
            Click here for details
          </a>
        </Link>
      </div>
      <Header />
      <main className="flex-1 w-full">{props.children}</main>
      <Footer />
    </div>
  );
}
