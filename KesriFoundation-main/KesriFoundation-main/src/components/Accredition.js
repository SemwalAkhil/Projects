import React from "react"
import Image from "next/image"

export const Accredition = () => {
  return (
    <div className="my-5 flex flex-col break-word">
      <div className="text-center ">
        <h1 className="font-serif text-5xl mb-5 text-blue-900 font-extrabold max-md:text-4xl">
          Our Accredition
        </h1>
      </div>
      <div className="flex flex-wrap justify-around gap-6">
        <Image
          src={"/certificates/iso9001.png"}
          width={400}
          height={400}
          className="border-2 border-blue-900"
        />
        <Image
          src={"/certificates/iso21001.png"}
          width={400}
          height={400}
          className="border-2 border-blue-900"
        />
        <Image
          src={"/certificates/iso45001.png"}
          width={400}
          height={400}
          className="border-2 border-blue-900"
        />
        <Image
          src={"/certificates/iaap.png"}
          width={400}
          height={400}
          className="border-2 border-blue-900"
        />
        <Image
          src={"/certificates/iaf.png"}
          width={400}
          height={400}
          className="border-2 border-blue-900"
        />
        <Image
          src={"/certificates/msme.png"}
          width={400}
          height={400}
          className="border-2 border-blue-900"
        />
        <Image
          src={"/certificates/apcda.jpg"}
          width={400}
          height={400}
          className="border-2 border-blue-900"
        />
      </div>
    </div>
  );
};
