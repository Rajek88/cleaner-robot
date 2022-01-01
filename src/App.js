import { ref, set } from "firebase/database";
import { database } from "./config";

function App() {
  // x axis control
  const left = async () => {
    await set(ref(database, "x/"), {
      cmd: "left",
    });
    // to execute a funtion after a delay dont pass the () with function name
    setTimeout(() => {
      disableLeft();
    }, 1000);
    return;
  };
  const disableLeft = async () => {
    console.log("Left");
    await set(ref(database, "x/"), {
      cmd: "false",
    });
    return;
  };
  const right = async () => {
    await set(ref(database, "x/"), {
      cmd: "right",
    });
    // to execute a funtion after a delay dont pass the () with function name
    setTimeout(() => {
      disableRight();
    }, 1000);
    return;
  };
  const disableRight = async () => {
    console.log("Right");
    await set(ref(database, "x/"), {
      cmd: "false",
    });
    return;
  };

  // y axis control

  const forward = async () => {
    await set(ref(database, "x/"), {
      cmd: "forward",
    });
    // to execute a funtion after a delay dont pass the () with function name
    setTimeout(() => {
      disableForward();
    }, 7000);
    return;
  };
  const disableForward = async () => {
    console.log("Forward");
    await set(ref(database, "x/"), {
      cmd: "false",
    });
    return;
  };

  const backward = async () => {
    await set(ref(database, "x/"), {
      cmd: "backward",
    });
    // to execute a funtion after a delay dont pass the () with function name
    setTimeout(() => {
      disableBackward();
    }, 2000);
    return;
  };
  const disableBackward = async () => {
    console.log("Backward");
    await set(ref(database, "x/"), {
      cmd: "false",
    });
    return;
  };

  return (
    <div className="App">
      <div className="leftdir">
        <button onClick={left}>
          <i className="fas fa-arrow-left"></i>
        </button>
        <button onClick={right}>
          <i className="fas fa-arrow-right"></i>
        </button>
      </div>
      <div className="updir">
        <button onClick={forward}>
          <i className="fas fa-arrow-up"></i>
        </button>
        <button onClick={backward}>
          <i className="fas fa-arrow-down"></i>
        </button>
      </div>
    </div>
  );
}

export default App;
