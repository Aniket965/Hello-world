
" Specify a directory for plugins
call plug#begin('~/.vim/plugged')
" On-demand loading
Plug 'scrooloose/nerdtree'

Plug 'scrooloose/nerdcommenter'
map <C-t> :NERDTreeToggle<CR>

Plug 'townk/vim-autoclose'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'w0rp/ale'
" Set this. Airline will handle the rest.
let g:airline#extensions#ale#enabled = 1
Plug 'SirVer/ultisnips'
" Snippets are separated from the engine. Add this if you want them:
"Plug 'honza/vim-snippets'
" Trigger configuration. Do not use <tab> if you use https://github.com/Valloric/YouCompleteMe.
let g:UltiSnipsExpandTrigger="<tab>"
let g:UltiSnipsJumpForwardTrigger="<c-b>"
let g:UltiSnipsJumpBackwardTrigger="<c-z>"

" If you want :UltiSnipsEdit to split your window.
let g:UltiSnipsEditSplit="vertical"

let g:UltiSnipsSnippetDirectories=["UltiSnips"]
" Initialize plugin system
call plug#end()

:let mapleader=","
filetype plugin on

" colorscheme
syntax enable
set background=dark
colorscheme solarized

:imap hh <Esc>
:set number
:set relativenumber
:set tabstop=4
