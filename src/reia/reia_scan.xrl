Definitions.

Digit = [0-9]
Whitespace = [\s]

Rules.   

{Digit}+\.{Digit}+ : build_float(TokenChars, TokenLine).
{Digit}+ : build_integer(TokenChars, TokenLine).

{Whitespace}+ : skip_token.

%% special characters and single character operators
\n :                  {token,{eol,TokenLine}}.
\* :                  {token,{'*',TokenLine}}.
/ :                   {token,{'/',TokenLine}}.
\+ :                  {token,{'+',TokenLine}}.
- :                   {token,{'-',TokenLine}}.
\^ :                  {token,{'^',TokenLine}}.
& :                   {token,{'&',TokenLine}}.
\| :                  {token,{'|',TokenLine}}.
\< :                  {token,{'<',TokenLine}}.
\> :                  {token,{'>',TokenLine}}.
= :                   {token,{'=',TokenLine}}.
\. :                  {token,{'.',TokenLine}}.
, :                   {token,{',',TokenLine}}.
: :                   {token,{':',TokenLine}}.
! :                   {token,{'!',TokenLine}}.
\? :                  {token,{'?',TokenLine}}.
; :                   {token,{';',TokenLine}}.
\( :                  {token,{'(',TokenLine}}.
\) :                  {token,{')',TokenLine}}.
\{ :                  {token,{'{',TokenLine}}.
} :                   {token,{'}',TokenLine}}.
\[ :                  {token,{'[',TokenLine}}.
\] :                  {token,{']',TokenLine}}.
\% :                  {token,{'%',TokenLine}}.
\~ :                  {token,{'~',TokenLine}}.

%% multi character operators
<< :                  {token,{'<<',TokenLine}}.
>> :                  {token,{'>>',TokenLine}}.
== :                  {token,{'==',TokenLine}}.
<> :                  {token,{'<>',TokenLine}}.
=== :                 {token,{'===',TokenLine}}.
&& :                  {token,{'&&',TokenLine}}.
\|\| :                {token,{'||',TokenLine}}.
\*= :                 {token,{'*=',TokenLine}}.
/= :                  {token,{'/=',TokenLine}}.
\%= :                 {token,{'%=',TokenLine}}.
\+= :                 {token,{'+=',TokenLine}}.
-= :                  {token,{'-=',TokenLine}}.
&= :                  {token,{'&=',TokenLine}}.
\^= :                 {token,{'^=',TokenLine}}.
\|= :                 {token,{'|=',TokenLine}}.
\|\|= :               {token,{'||=',TokenLine}}.
<= :                  {token,{'<=',TokenLine}}.
>= :                  {token,{'>=',TokenLine}}.
\*\* :                {token,{'**',TokenLine}}.

Erlang code.  

-export([build_integer/2, build_float/2]).

build_integer(Chars, Line) ->
  {token, {integer, Line, list_to_integer(Chars)}}.
  
build_float(Chars, Line) ->
  {token, {float, Line, list_to_float(Chars)}}.