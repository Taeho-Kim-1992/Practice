# Practice

# Author		:	Taeho Kim
# About			:	C language practice
# Contents		:	Data Structure practice
		- linkedlist (2020.09.26)
		- cmake
# Environment	: Ubuntu 20.04 Linux
				: vim
.vimrc
---------------------------

set nocompatible              " be iMproved, required
filetype off                  " required
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'tpope/vim-fugitive'
Plugin 'git://git.wincent.com/command-t.git'
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
Plugin 'vim-airline/vim-airline'
Plugin 'scrooloose/nerdtree'
Plugin 'airblade/vim-gitgutter'
Plugin 'scrooloose/syntastic'
Plugin 'ctrlpvim/ctrlp.vim'
Plugin 'nanotech/jellybeans.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'scrooloose/nerdcommenter'
Plugin 'Lokaltog/vim-easymotion'
call vundle#end()            " required
"filetype plugin indent on    " required

nmap <C-z> :NERDTree<CR>
nmap nerd :NERDTree<CR>

let NERDTreeShowHidden=1
" let NERDTreeQuitOnOpen=1
let g:ctrlp_custom_ignore = {
  \ 'dir':  '\.git$\|vendor$',
    \ 'file': '\v\.(exe|so|dll)$'
\ }
color jellybeans
" Tag List 환경설정
filetype on                                 "vim filetype on
"Source Explorer 환경설정
nmap <F8> :SrcExplToggle<CR>                "F8 Key = SrcExpl Toggling
nmap <C-H> <C-W>h                           "왼쪽 창으로 이동
nmap <C-J> <C-W>j                           "아래 창으로 이동
nmap <C-K> <C-W>k                           "윗 창으로 이동
nmap <C-L> <C-W>l                           "오른쪽 창으로 이동
" NERDCommenter 설정 시작
" Add spaces after comment delimiters by default
let g:NERDSpaceDelims = 1
let g:NERDCompactSexyComs = 1
let g:NERDDefaultAlign = 'left'
let g:NERDAltDelims_java = 1
let g:NERDCustomDelimiters = { 'c': { 'left': '/**','right': '*/' } }
let g:NERDCommentEmptyLines = 1
let g:NERDTrimTrailingWhitespace = 1

map <Leader>cc <plug>NERDComToggleComment
map <Leader>c<space> <plug>NERDComComment

" YCM setting
let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
let g:ycm_confirm_extra_conf = 0
let g:ycm_key_list_select_completion = ['<C-j>']
let g:ycm_key_list_previous_completion=['<C-k>']
let g:ycm_autoclose_preview_window_after_completion = 1
let g:ycm_warning_symbol = '>*'
let g:ycm_filetype_blacklist = {}

nnoremap <leader>g :YcmCompleter GoTo<CR>
nnoremap <leader>gg :YcmCompleter GoToImprecise<CR>
nnoremap <leader>d :YcmCompleter GoToDeclaration<CR>
nnoremap <leader>t :YcmCompleter GetType<CR>
nnoremap <leader>p :YcmCompleter GetParent<CR>


set nu
set title
set showmatch
set ruler
if has("syntax")
 syntax on
endif
set t_Co=256
set autoindent
set cindent
set smartindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set smarttab
set expandtab
set paste
set mouse-=a
set encoding=utf-8
set termencoding=utf-8
set cursorline
set laststatus=2
set statusline=\ %<%l:%v\ [%P]%=%a\ %h%m%r\ %F\
set ignorecase
set hlsearch
highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/

au BufReadPost *
\ if line("'\"") > 0 && line("'\"") <= line("$") |
\ exe "norm g`\"" |
\ endif
" Markdown 문법 설정 (Git 에서 사용)
augroup markdown
    " remove previous autocmds
    autocmd!
    " set every new or read *.md buffer to use the markdown filetype
    autocmd BufRead,BufNew *.md setf markdown
augroup END

nnoremap <F5> :let _s=@/<Bar>:%s/\s\+$//e<Bar>:let @/=_s<Bar><CR>
----------------------------
