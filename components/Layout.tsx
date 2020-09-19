import { Header } from "./Header";
import { Footer } from "./Footer";

type Props = {
  children: React.ReactNode;
};

export function Layout(props: Props) {
  return (
    <div className="flex flex-col min-h-screen dark:bg-nit-black bg-nit-white">
      <Header />
      <main className="flex-1 w-full">{props.children}</main>
      <Footer />
    </div>
  );
}
