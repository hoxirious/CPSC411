/*
1. E -> T E'
2. E' -> + T E' | ε
3. T -> F T'
4. T' -> * F T' |ε
5. F -> ( E ) | num
*/

type AST = {
  kind: "E" | "E_" | "T" | "T_" | "F";
  left?: AST;
  right?: AST;
  value?: number;
};

type Special_Char = "PLUS" | "MUL" | "O_PAREN" | "C_PAREN";
type Token = { kind: Special_Char | "NUM"; value?: string };

type output = {
  ast: AST;
  remainingTokens: Token[];
};
function parser(tokens: Token[]): AST {
  const { ast, remainingTokens } = parse_E(tokens);

  if (remainingTokens.length > 0) {
    throw Error("parse error");
  }
  return ast;
}

function parse_E(tokens: Token[]): output {
  const { ast: t, remainingTokens: r_tokens } = parse_T(tokens);
  const { ast: e_, remainingTokens } = parse_E_prime(r_tokens);
  return { ast: { kind: "E", left: t, right: e_ }, remainingTokens };
}

function parse_E_prime(tokens: Token[]): output {
  const [headToken, ...restTokens] = tokens;

  if (headToken && headToken.kind === "PLUS") {
    const { ast: t, remainingTokens: r_tokens } = parse_T(restTokens);
    const { ast: e_, remainingTokens } = parse_E_prime(r_tokens);
    return {
      ast: { kind: "E_", right: t, left: e_ },
      remainingTokens,
    };
  }

  return { ast: { kind: "E_" }, remainingTokens: tokens };
}

function parse_T(tokens: Token[]): output {
  const { ast: f, remainingTokens: r_tokens } = parse_F(tokens);
  const { ast: t_, remainingTokens } = parse_T_prime(r_tokens);
  return { ast: { kind: "T", left: f, right: t_ }, remainingTokens };
}

function parse_T_prime(tokens: Token[]): output {
  const [headToken, ...restTokens] = tokens;
  if (headToken && headToken.kind === "MUL") {
    const { ast: f, remainingTokens: r_tokens } = parse_F(restTokens);
    const { ast: t_, remainingTokens } = parse_T_prime(r_tokens);
    return {
      ast: { kind: "T_", right: f, left: t_ },
      remainingTokens,
    };
  }

  return { ast: { kind: "T_" }, remainingTokens: tokens };
}

function parse_F(tokens: Token[]): output {
  const [headToken, ...restTokens] = tokens;
  if (headToken.kind === "O_PAREN") {
    const { ast: e, remainingTokens } = parse_E(restTokens);
    const [nextToken, ...otherTokens] = remainingTokens;
    if (nextToken.kind === "C_PAREN") {
      return {
        ast: { kind: "F", right: e },
        remainingTokens: otherTokens,
      };
    }
  }

  if (headToken.kind === "NUM") {
    return {
      ast: { kind: "F", value: Number(headToken.value) },
      remainingTokens: restTokens,
    };
  }

  throw Error("parse error: unexpected token");
}

const tokens: Token[] = [
  { kind: "NUM", value: "2" },
  { kind: "PLUS" },
  { kind: "NUM", value: "3" },
  { kind: "MUL" },
  { kind: "O_PAREN" },
  { kind: "NUM", value: "10" },
  { kind: "PLUS" },
  { kind: "NUM", value: "3" },
  { kind: "C_PAREN" },
];
console.log(JSON.stringify(parser(tokens)));
